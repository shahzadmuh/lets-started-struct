# Declaration of variables
CC = gcc
CC_FLAGS = -shared -fPIC -I/usr/include/python2.7 \
	-Wall -Wextra -Wno-unused-parameter -O2 -g

# File names
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.so)

# Main target
all: $(OBJECTS)

# Object files
%.so: %.c
	$(CC) $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f *.so

.PHONY: all run clean
