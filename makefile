
BIN = /opt/gbdk-n-master/bin
NEW = ./new

LCC  = /opt/gbdk/bin/lcc
OLD = ./old

make:
	mkdir -p $(OLD)
	$(LCC) -Wa-l -c -o $(OLD)/main.o main.c
	$(LCC) -Wl-m -Wl-yt1 -o $(OLD)/output.gb $(OLD)/main.o
	mkdir -p $(NEW)
	$(BIN)/gbdk-n-compile.sh main.c -o $(NEW)/main.rel
	$(BIN)/gbdk-n-link.sh $(NEW)/main.rel -o $(NEW)/main.ihx
	$(BIN)/gbdk-n-make-rom.sh $(NEW)/main.ihx main.gb

clean:
	rm *.lst *.o *.map *.gb
