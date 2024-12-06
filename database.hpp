#ifndef DATABASE 
#define DATABASE

#include <cstddef>

enum DB_TYPE{
	INTEGER,
	BOOLEAN,
	STRING,
};

typedef struct {
	void *ptr;
	DB_TYPE type;
	size_t size;
} ROW;

typedef struct {
	unsigned int colums_c, rows_c;
	ROW entries[0];
} DB;

DB *create_database(unsigned int rows, unsigned int colums, DB_TYPE typess[0]);
void delete_database(DB* db);

//rows start at 0 - (index at array)
//TODO: MAYBE use user defined index instead
int assign_row(DB* db, unsigned int row, void *content);
void clear_row(DB* db, unsigned int row);
void get_row(DB* db, unsigned int row, void *output);

void delete_row(DB *db, unsigned int row);
void add_row(DB* db, unsigned int row); //pass the row behind which you want the new row

#endif