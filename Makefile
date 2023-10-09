
CC = gcc
CFLAGS = -Wall
OBJECTS = bmp.o main.o
SRC = bmp.c main.c
TARGET = infobmp

all: $(TARGET)
	@ echo "Done!"

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

$(OBJECTS): $(SRC)
	$(CC) -c $(CFLAGS) $^

clean:
	@ rm -f *.o
	@ echo "Cleaned up current working directory."

