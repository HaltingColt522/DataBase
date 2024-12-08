#include <string.h>
#include "./database.h"

void assign_row(DB* db, unsigned int row, void *content) {
	memcpy(db->entries[row].ptr, content, db->entries[row].size);
}

void get_row(DB* db, unsigned int row, void *output) {
	memcpy(output, db->entries[row].ptr, db->entries[row].size);
}

void clear_row(DB* db, unsigned int row) {
	memset(db->entries[row].ptr, 0, db->entries[row].size);
}