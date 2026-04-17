# compiler
CC = gcc

# flags
CFLAGS = -Wall -Wextra -std=c11 -O2

# target name (output binary)
TARGET = working

# default rule
all: $(TARGET)

$(TARGET): working.c
	$(CC) $(CFLAGS) working.c -o $(TARGET)

# run the program
run: $(TARGET)
	./$(TARGET)

# clean build files
clean:
	rm -f $(TARGET)
