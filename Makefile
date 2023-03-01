compile:
	gcc src/main.c src/Point.c src/ListPoint.c -lm -o bin/main 
run:
	bin/main