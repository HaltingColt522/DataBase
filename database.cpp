#include <stdlib.h>
#include "./database.hpp"

db *create_database(unsigned int rows, unsigned int colums, DB_TYPE type, unsigned int string_size) {
	db *db = malloc(sizeof(db));
	size_t type_size;

	switch (type){
		case INTEGER:
			type_size = sizeof(int);
		case BOOLEAN:
			type_size = sizeof(bool);
		case STRING:
			if (string_size == 0) {
				return nullptr;
			}
			type_size = sizeof(char) * string_size;
	}

	db_size = (rows++) * (colums++) * type_size;

	db_ptr = malloc(db_size);
	memset(db_ptr, 0, db_size);

	return db;
}