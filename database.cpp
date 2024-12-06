#include <cstdlib>
#include <cstring>
#include "./database.hpp"

DB *create_database(unsigned int rows, unsigned int colums, DB_TYPE types[0]) {
	size_t db_size = sizeof(DB) + (sizeof(ROW) * rows);
	DB* db = (DB *)malloc(db_size);
	memset((void*)db, 0, db_size);

	db->colums_c = colums;
	db->rows_c = rows;

	for (int i = 0; i < rows; i++) {
		db->entries[i].type = types[i];

		size_t type_size;
		switch (types[i]) {
			case INTEGER:
				type_size = sizeof(int);
			case BOOLEAN:
				type_size = sizeof(bool);
			case STRING:
				#define STRING_SIZE 10
				type_size = sizeof(char) * STRING_SIZE;
		}
		db->entries[i].ptr = malloc(type_size * colums);
		memset(db->entries[i].ptr, 0, type_size * colums);
		db->entries[i].size = type_size * colums;
	}

	return db;
}

void delete_database(DB* db) {
	for (int i = 0; i < db->rows_c; i++) {
		free(db->entries[i].ptr);
	}
	free(db);

	return;
}
