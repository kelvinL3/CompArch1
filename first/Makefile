all:
	gcc first.c -O3 -g

clean:
	rm ./first

run:
	cat test.txt | ./first

debug:
	gcc first.c -Wall -Werror -fsanitize=address -g