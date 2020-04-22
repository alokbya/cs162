CC = g++
CPPFLAGS = -Wall -g -std=c++11
app:	app.o functions.o

app.o: 	functions.h

functions.o:	functions.h

.PHONY: clean
clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app

