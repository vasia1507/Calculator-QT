all: datatypes.o rpn.o calculator.o
	gcc $^ -o ./calculator -lm

clean:
	rm -rf *.o ./calculator

rebuild: clean all
