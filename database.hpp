#pragma once

enum DB_TYPE{
	INTEGER,
	BOOLEAN,
	STRING,
};

struct {
	void *db_ptr;
	size_t db_size;
	DB_TYPE db_type;
} db;

void *create_database(unsigned int rows, unsigned int colums, DB_TYPE type, unsigned int string_size=0);