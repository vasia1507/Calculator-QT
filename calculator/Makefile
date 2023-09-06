CC := gcc
CFLAGS := -Wall -Wextra -Werror

all: datatypes.o rpn.o calculator.o
	$(CC) $(CFLAGS) $^ -o ./calculator -lm

clean:
	rm -rf *.o ./calculator

rebuild: clean all
