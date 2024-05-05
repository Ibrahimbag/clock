CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c11 -g
LIBS = -lncursesw
OBJ = main.o digits.o
HEADERS = digits.h
EXEC = clock

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS) 

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXEC)
