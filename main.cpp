#include <iostream>
#include "dataBase.hpp"

int main() {
	DataBase TestBase = DataBase("Testdatenbank");
	Column<int> TestColumn(1, "ID", true);
	Column<std::string> TestColumn2(2, "ISBN", false);
	Column<float> TestColumn3(3, "category", false);
	Column<bool> TestColumn4(4, "name", false);


	//various, depends on numOfColumns e.g. with 5 columns: (numOfColumns out of Table)
	//TestRow.addContent(1, 'Hackfleisch', false, 82, 9);
	 
	
	//various, depends on numOfColumns e.g. with 8 columns: (numOfColumns out of Table)
	//TestRow2.addContent(1, 'Hackfleisch', false, 82, 9, 'Äquator', -1.83, true);

	std::cout << "Starting to run...\n";

	std::cout << "Creating database...\n";

	std::cout << "Outputting content...\n";

	std::cout << "Basedebug" << TestBase.name << "\n";
	
	TestColumn.printColumn();
	TestColumn2.printColumn();
	TestColumn3.printColumn();
	TestColumn4.printColumn();
}