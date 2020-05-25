CC = g++
CPPFLAGS = -Wall -g -std=c++11

logs:	logs.o syslog.o entries.o

logs.o: 	syslog.o entries.o

syslog.o:	syslog.h

entries.o:	entries.h

.PHONY: clean

clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f logs

