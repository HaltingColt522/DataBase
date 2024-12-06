files = main.cpp database.cpp access.cpp dynamic.cpp

run:
	g++ ${files} -o test.exe -ggdb -static
	./test.exe

object:
	g++ ${files} -o database.o -static