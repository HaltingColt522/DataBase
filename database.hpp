#ifndef DATABASE 
#define DATABASE

enum DB_TYPE{
	INTEGER,
	BOOLEAN,
	STRING,
};

typedef struct {
	void *ptr;
	DB_TYPE type;
} ROW;

typedef struct {
	unsigned int colums_c, rows_c;
	ROW entries[0];
} DB;

DB *create_table(unsigned int rows, unsigned int colums, DB_TYPE typess[0]);
void delete_table(DB* db);

#endif