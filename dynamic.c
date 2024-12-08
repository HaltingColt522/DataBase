#include <string.h>
#include <stdlib.h>
#include "./database.h"

void delete_row(DB *db, unsigned int row) {
	unsigned int row1 = row+1;
	db->rows_c--;
	free(db->entries[row].ptr);
	if (row1 > db->rows_c) {
		return;
	}
	memmove(&db->entries[row], &db->entries[row1], &db->entries[db->rows_c] - &db->entries[row1]);
}

DB *add_row(DB *db, unsigned int row, DB_TYPE type) {
	db->rows_c++;

	db = (DB *)realloc(db, sizeof(DB) + (sizeof(ROW) * db->rows_c));
	unsigned int row2 = row+2;
	unsigned int row1 = row+1;
	if (row2 > db->rows_c){
		return NULL;
	}
	memmove(&db->entries[row2], &db->entries[row1], (&db->entries[db->rows_c] - &db->entries[row2]) * sizeof(ROW));
	
	db->entries[row1].type = type;

	size_t type_size;
	switch (type) {
		case INTEGER:
			type_size = sizeof(int);
			break;
		case BOOLEAN:
			type_size = sizeof(bool);
			break;
		case STRING:
			#define STRING_SIZE 10
			type_size = sizeof(char) * STRING_SIZE;
			break;
	}

	db->entries[row1].ptr = malloc(type_size * db->colums_c);
	db->entries[row1].size = type_size * db->colums_c;

	return db;
}