CC=gcc
CFLAGS=-g 
OBJS=main.o 
TARGET=main.exe
 

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f *.o
	rm -f $(TARGET)
