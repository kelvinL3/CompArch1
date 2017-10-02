all:
	gcc first.c -o first

clean:
	rm ./first

run:
	./first test.txt

debug:
	gcc first.c -Wall -Werror -fsanitize=address -g