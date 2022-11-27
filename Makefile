OBJS = bitonic_sorter.o helper.o main.o
CFLAG = -Wall -g -O2 
LIBS = -pthread
CC = g++
# sets makefile compiler

bitonic_sorter: $(OBJS)
	$(CC) -o bitonic_sorter $(OBJS) $(LIBS)

main.o: main.cpp bitonic_sorter.h
	$(CC) -c main.cpp $(CFLAG)

bitonic_sorter.o: bitonic_sorter.cpp bitonic_sorter.h helper.h constants.h
	$(CC) -c bitonic_sorter.cpp $(CFLAG)

helper.o: helper.cpp helper.h constants.h
	$(CC) -c helper.cpp $(CFLAG)


clean:
# establishes clean command to rm
	-rm -f  *.o *.core

