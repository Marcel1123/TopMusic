#fisier folosit pentru compilarea serverului concurent & clientului TCP

all:
	gcc Server/ServerTopMusic.c -l sqlite3 -o sTopMusic
	gcc Client/ClientTopMusic.c -o cTopMusic
clean:
	rm -f *~ sTopMusic cTopMusic
