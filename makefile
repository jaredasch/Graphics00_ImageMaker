all: picmaker.c
	gcc -o out picmaker.c
	./out

clean:
	rm out
