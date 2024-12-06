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

void *create_database(unsigned int rows, unsigned int colums, DB_TYPE types[0]);

#endif