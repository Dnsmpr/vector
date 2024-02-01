CURRENT_DIR = $(shell pwd)
CC = gcc
OPT = -O0
SRC = $(CURRENT_DIR)/src

TARGET = bin
DEPFLAGS = -MP -MD
INCDIR = $(CURRENT_DIR) $(SRC)
CFILES = $(foreach D, $(INCDIR), $(wildcard $(D)/*.c))
OBJECTS = $(patsubst %.c, %.o, $(CFILES))
DEPFILES = $(patsubst %.c, %.d, $(CFILES))
CFLAGS=-Wall -g -Wstrict-prototypes -Wcast-align -Wundef -std=c99 $(foreach D, $(INCDIR), -I$(D)) $(DEPFLAGS) $(OPT)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS) $(TARGET) $(DEPFILES)

-include $(DEPFILES)
