parenthesis : parenthesis.o par_functions.o
		gcc -g -ansi -Wall parenthesis.o par_functions.o -o parenthesis
		
parenthesis.o : parenthesis.c par.h
		gcc -c -ansi -Wall parenthesis.c -o parenthesis.o
		
par_functions.o : par_functions.c par.h
		gcc -c -ansi -Wall par_functions.c -o par_functions.o
