magic:	magic.c
	gcc -Wall -ansi -pedantic -g magic.c -o magic
	
run1:	magic	input.txt
	./magic < input.txt
	
run2:	magic	input.txt
	./magic
