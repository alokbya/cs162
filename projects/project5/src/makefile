
CC = g++
CPPFLAGS = -Wall -g -std=c++11

main:	main.o messageList.o message.o helpers.o LinkedList.o

main.o:	message.o helpers.o LinkedList.o

message.o:	message.h

helpers.o:	helpers.h

LinkedList.o:	LinkedList.h

.PHONY: clean

clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app
