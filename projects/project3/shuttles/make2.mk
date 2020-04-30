CC = g++
CPPFLAGS = -Wall -g -std=c++11

app:	app.o person.o shuttle.o spacehelpers.o

app.o: 	person.h shuttle.h spacehelpers.h

person.o:	person.h

shuttle.o:	shuttle.h

spacehelpers.o:	spacehelpers.h

.PHONY: clean

clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app

