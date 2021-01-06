CC = g++
CPPFLAGS = -Wall -g -std=c++17
main:	main.o song.o songList.o tools.o

main.o: 	main.cpp

song.o:	song.h

songList.o: songList.h

tools.o: tools.h

.PHONY: clean
clean:	
	$(info -- cleaning the directory --)
	rm -f *.o
	rm -f main