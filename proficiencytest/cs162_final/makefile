CC = g++
CPPFLAGS = -Wall -g -std=c++11
main:	main.o supplied.o list.o

main.o:	list.h

list.o:	list.h

.PHONY: clean
clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app

