CC=g++
CFLAGS=-g 
OBJS=main.o Double_linked_list.o
TARGET=main.exe
 
 all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f *.o
	rm -f $(TARGET)