CC=gcc
CFLAGS=-g -I. 
DEPS = Double_linked_list.h Deque.h
OBJS = main.o
TARGET=main.exe
 
 all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f $(TARGET)
