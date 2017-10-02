all:
	gcc first.c -O3 -g

clean:
	rm ./first

run:
	./first test.txt

debug:
	gcc first.c -Wall -Werror -fsanitize=address -g