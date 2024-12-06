#include <iostream>
#include "database.hpp"

int main() {
	// this function is used to test the lib before porting to lazarus

	std::cout << "Starting to run...\n";

	std::cout << "Creating database...\n";

	DB_TYPE type[1] = {INTEGER};
	void *db = create_database(1, 1, type);

	return 0;
}