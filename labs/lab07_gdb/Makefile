CXXFLAGS = -g -Wall -o

all: date

date:	main.cc Date.o Exceptions.o
	g++ $(CXXFLAGS) date main.cc Date.o Exceptions.o

Date.o:	Date.cc Date.h Debug.h
	g++ -c $(CXXFLAGS) Date.o Date.cc

Exceptions.o:	Exceptions.cc Exceptions.h
	g++ -c $(CXXFLAGS) Exceptions.o Exceptions.cc

clean:
	rm -f date *.o
