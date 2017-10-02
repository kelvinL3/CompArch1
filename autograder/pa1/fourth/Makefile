all:
	gcc fourth.c -o fourth

clean:
	rm ./fourth

run:
	./fourth test.txt

debug:
	gcc fourth.c -Wall -Werror -fsanitize=address -g