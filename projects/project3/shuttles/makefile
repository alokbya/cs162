CC = g++
CPPFLAGS = -Wall -g -std=c++11
app:	app.o shuttle.o

app.o: 	shuttle.h

shuttle.o:	shuttle.h

.PHONY: clean
clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app

