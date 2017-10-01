all:
	gcc first.c -O3 -g

clean:
	rm a.out

run:
	cat test.txt | ./a.out

debug:
	gcc first.c -Wall -Werror -fsanitize=address -g