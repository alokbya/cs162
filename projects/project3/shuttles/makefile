CC = g++
CPPFLAGS = -Wall -g -std=c++11

app:	app.o spacehelpers.o person.o shuttle.o 

app.o: 	spacehelpers.h person.h shuttle.h 

spacehelpers.o:	spacehelpers.h

person.o:	person.h spacehelpers.h

shuttle.o:	shuttle.h spacehelpers.h


.PHONY: clean

clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app

