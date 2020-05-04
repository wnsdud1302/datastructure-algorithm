CC=gcc
CFLAGS=-g 
OBJS=main.o Stack.o
TARGET=main.exe
 

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: Stack.h main.c
Stack.o: Stack.h Stack.c

clean:
	rm -f *.o
	rm -f $(TARGET)
