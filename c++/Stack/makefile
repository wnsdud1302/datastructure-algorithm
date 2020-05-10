CC=g++
CFLAGS=-g 
OBJS=main.o Stack.o
TARGET=main.exe
 
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)


clean:
	rm -f *.o
	rm -f $(TARGET)
