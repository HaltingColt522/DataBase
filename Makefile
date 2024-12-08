files = main.cpp database.c access.c dynamic.c

run:
	g++ ${files} -o test.exe -ggdb -static
	./test.exe

object:
	gcc database.c access.c dynamic.c -o database.o -static -nostartfiles