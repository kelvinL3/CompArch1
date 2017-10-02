all:
	gcc eighth.c -o eighth

clean:
	rm ./eighth

run:
	./eighth test.txt

debug:
	gcc eighth.c -Wall -Werror -fsanitize=address -g