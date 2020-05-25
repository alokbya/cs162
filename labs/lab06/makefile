CC = g++
CPPFLAGS = -Wall -g -std=c++11

app06: app06.o list.o

app06.o: list.h

list.o: list.h

.PHONY: clean
clean:
	$(info -- cleaning the directory -- )
	rm -f *.o
	rm -f app06
