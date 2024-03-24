OFILES = testsorting.o Stable.o

TARGET = testsorting

CC = gcc
CFLAGS = -g -Wall -Wextra -Wmissing-prototypes --pedantic -std=c99

.PHONY: all clean run

LDFLAGS = -lm

all: $(TARGET)
clean:
	rm -f $(OFILES) $(TARGET)
run: $(TARGET)
	./$(TARGET) 1000 0

$(TARGET): $(OFILES)
	$(CC) -o $(TARGET) $(OFILES) Sort.o $(LDFLAGS) -g

Stable.o: Stable.c Stable.h Sort.h
testsorting.o: testsorting.c Sort.h Stable.h
