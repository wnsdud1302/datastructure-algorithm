CC=g++
CFLAGS=-g -Wall
OBJS=main.o stack.o
TARGET= main.exe

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: stack.h main.cpp
	$(CC) -c -o main.o main.cpp

stack.o: stack.h stack.cpp
	$(CC) -c -o stack.o stack.cpp

clean:
	rm -f *.o
	rm -f $(TARGET)
