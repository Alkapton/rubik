TARGET = rubik
LIBS = -lncurses
CC = gcc
CFLAGS = -Wall
PREFIX ?= /usr

.PHONY: default all clean install
	
default: $(TARGET)
all: default

OBJECTS := $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS := $(wildcard *.h)
PREFIX := /usr
BIN_DIR = $(PREFIX)/bin
MAN_DIR = $(PREFIX)/share/man/man6

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
install:
	cp $(TARGET) $(BIN_DIR)/
	cp $(TARGET).6.gz $(MAN_DIR)

uninstall:
	rm $(BIN_DIR)/$(TARGET)
	rm $(MAN_DIR)/$(TARGET).6.gz
