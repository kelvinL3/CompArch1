all:
	gcc third.c -o third

clean:
	rm ./third

run:
	./third test.txt

debug:
	gcc third.c -Wall -Werror -fsanitize=address -g