CC=g++
CFLAGS=-g 
OBJS=main.o Array_Linked_list.o
TARGET=main.exe
 
 all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f *.o
	rm -f $(TARGET)