FLAGS = -W -O3

.PHONY = all clean cleanall

calc: calc.y calc.l
	bison -o calc_y.c -d calc.y 
	flex -o calc_l.c calc.l
	$(CC) $(FLAGS) -o calc calc_y.c calc_l.c -lm