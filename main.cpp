#include <iostream>
#include "database.hpp"

int main() {
	// this function is used to test the lib before porting to lazarus

	std::cout << "Starting to run...\n";

	std::cout << "Creating database...\n";
	DB_TYPE type[2] = {INTEGER, INTEGER};
	DB *db = create_database(2, 2, type);

	std::cout << "Assigning content...\n";
	int content[2] = {10, 100};
	assign_row(db, 0, content);
	int content2[2] = {7, 19};
	assign_row(db, 1, content2);


	std::cout << "Outputting content...\n";
	int output[2] = {0};
	get_row(db, 0, output);
	std::cout << output[0] << std::endl;
	std::cout << output[1] << std::endl;
	get_row(db, 1, output);
	std::cout << output[0] << std::endl;
	std::cout << output[1] << std::endl;

	std::cout << "Adding row...\n";
	db = add_row(db, 0, INTEGER); 
	std::cout << "Outputting content...\n";
	get_row(db, 1, output);
	std::cout << output[0] << std::endl;
	std::cout << output[1] << std::endl;
	get_row(db, 2, output);
	std::cout << output[0] << std::endl;
	std::cout << output[1] << std::endl;

	std::cout << "Deleting row...\n";
	delete_row(db, 2);

	std::cout << "Clearing row...\n";
	clear_row(db, 0);

	std::cout << "Deleting database...\n";
	delete_database(db);

	return 0;
}