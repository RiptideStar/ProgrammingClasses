CC = g++
CPPFLAGS = -Wall -g -std=c++17
app:	app.o student.o

app.o: 	student.h

student.o:	student.h

.PHONY: clean
clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app