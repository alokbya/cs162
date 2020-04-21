CC = g++
CPPFLAGS = -Wall -g -std=c++11
app:	app.o dtypes.o

app.o: 	dtypes.h

dtypes.o:	dtypes.h

.PHONY: clean
clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app

