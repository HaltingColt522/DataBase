#include <cstdlib>
#include <cstring>
#include "./database.hpp"

void *new_row(unsigned int colums_c, DB_TYPE type);

void *create_database(unsigned int rows, unsigned int colums, DB_TYPE types[0]) {

	size_t db_size = sizeof(DB) + (sizeof(ROW) * rows++); // one additional, if you want to expand the table
	DB* db = (DB *)malloc(db_size);
	memset((void*)db, 0, db_size);

	db->colums_c = colums;
	db->rows_c = rows;

	for (int i = 0; i < rows; i++) {
		db->entries[i].type = types[i];
		db->entries[i].ptr = new_row(rows, types[i]);
	}
}

void *new_row(unsigned int colums_c, DB_TYPE type) {
	size_t type_size;
	switch (type) {
		case INTEGER:
			type_size = sizeof(int);
		case BOOLEAN:
			type_size = sizeof(bool);
		case STRING:
			#define STRING_SIZE 10
			type_size = sizeof(char) * STRING_SIZE;
	}
}
