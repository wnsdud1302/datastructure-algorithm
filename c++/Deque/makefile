CC=g++
CFLAGS=-g -I. -fpermissive
DEPS = Double_linked_list.h Deque.h
OBJS = main.o
TARGET=main.exe
 
 all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f $(TARGET)