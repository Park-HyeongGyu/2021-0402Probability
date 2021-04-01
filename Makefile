CC=gcc
CFLAGS=-g -lm
TARGET=a.out
OBJS=four.o

$(TARGET) : $(OBJS) 
	$(CC) -o $@ $(OBJS) $(CFLAGS)
	rm *.o

four.o : four.c
	$(CC) $(CFLAGS) -c four.c 

clean:
	rm *.o *.out *.gch
