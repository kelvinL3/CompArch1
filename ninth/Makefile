all:
	gcc ninth.c -o ninth

clean:
	rm ./ninth

run:
	./ninth test.txt

debug:
	gcc ninth.c -Wall -Werror -fsanitize=address -g