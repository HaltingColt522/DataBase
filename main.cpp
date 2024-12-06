#include <iostream>
#include "database.hpp"

int main() {
	// this function is used to test the lib before porting to lazarus

	std::cout << "Starting to run...\n";

	std::cout << "Creating database...\n";
	DB_TYPE type[1] = {INTEGER};
	DB *db = create_table(1, 1, type);

	std::cout << "Deleting table...\n";
	delete_table(db);

	return 0;
}