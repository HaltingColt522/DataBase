files = main.cpp dataBase.cpp Table.cpp

run:
	g++ ${files} -o test.exe -ggdb
	./test.exe

object:
	g++ ${files} -o database.o