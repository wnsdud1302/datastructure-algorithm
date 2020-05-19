CC=gcc
CFLAGS=-g 
OBJS=main.o Double_Linked_list.o
TARGET=main.exe
 
 all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f *.o
	rm -f $(TARGET)