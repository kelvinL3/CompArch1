all:
	gcc fifth.c -o fifth

clean:
	rm ./fifth

run:
	./fifth test.txt

debug:
	gcc fifth.c -Wall -Werror -fsanitize=address -g