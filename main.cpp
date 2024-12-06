#include <iostream>
#include "database.cpp"

int main() {
	// this function is used to test the lib before porting to lazarus

	std::cout << "Starting to run...\n";

	std::cout << "Creating database...\n";
	void *db = create_database(1, 1, INTEGER);
}