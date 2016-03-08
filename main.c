
//  main.c
//  wavy
//  [08/03/2016]

//  wavy screen effect

#include <gb/gb.h>
#include "gfx.h"

UBYTE ix, iy, counter;

void LCD_Interrupt(void) NONBANKED {
    SCY_REG = fx[counter]>>1;
    counter++;
    if(counter >= 109) counter = 0;
}

void main(void) NONBANKED {
    
    HIDE_SPRITES;
    HIDE_BKG;
    
    counter = 0;
    
    STAT_REG = 8;
    
    disable_interrupts();
    add_LCD(LCD_Interrupt);
    enable_interrupts();
    
    // set background
    set_bkg_data(0, 0, tiles);
    for (ix = 0; ix != 21; ix += 7) {
        for (iy = 0; iy != 21; iy += 7) {
            set_bkg_tiles(ix, iy, 7, 7, map);
        }
    }
    
    set_interrupts(LCD_IFLAG);
    
    SHOW_BKG;
    SHOW_SPRITES;
    
    for (;;) wait_vbl_done();

}
