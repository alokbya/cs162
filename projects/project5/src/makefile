
CC = g++
CPPFLAGS = -Wall -g -std=c++11

main:	main.o message.o helpers.o messagelist.o

main.o:	message.o helpers.o messagelist.o

message.o:	message.h

helpers.o:	helpers.h

messagelist.o:	messagelist.h

.PHONY: clean

clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app
