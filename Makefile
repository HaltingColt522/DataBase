files = main.cpp database.cpp access.cpp dynamic.cpp

run:
	g++ ${files} -o test.exe
	./test.exe

object:
	g++ ${files} -o database.o