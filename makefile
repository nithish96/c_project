INC_PATH = -I/usr/local/include/player-3.0
LIB_PATH = -L/usr/local/lib64 -lplayerc -lm -lz -lplayerinterface -lplayerwkb -lplayercommon
proj: proj.c
	gcc -o proj $(INC_PATH) proj.c $(LIB_PATH)
clean:
	rm -rf proj
