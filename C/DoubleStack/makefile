CC=gcc
CFLAGS=-g 
OBJS= main.o DoubleStack.o 
TARGET=main.exe

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f $(TARGET)
