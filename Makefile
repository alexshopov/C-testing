CC = gcc

CFLAGS=-Wall -pedantic -Werror

LDFLAGS = -L /local/lib -lcunit

default: calculator.o operations.o
	$(CC) $(CFLAGS) -o calculator calculator.o operations.o

calculator.o : calculator.c operations.h
	$(CC) $(CFLAGS) -c calculator.c

operations.o : operations.c operations.h
	$(CC) $(CFLAGS) -c operations.c

testprogram.o : testprogram.c operations.h
	$(CC) $(CFLAGS) -c testprogram.c

test: testprogram.o operations.o
	$(CC) $(CFLAGS) -o testprogram testprogram.o operations.o -lcunit && ./testprogram

clean:
	rm *.o *.mif assembler testprogram
