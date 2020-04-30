CC = g++
CPPFLAGS = -Wall -g -std=c++11
main:	main.o supplied.o array.o

main.o: 	array.h

array.o:	array.h

.PHONY: clean
clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app

