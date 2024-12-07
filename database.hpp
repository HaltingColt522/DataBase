#pragma once
#include <string>
#include "columns.hpp"

enum DB_TYPE {
	INTEGER,
	BOOLEAN,
	STRING
};

class DataBase
{
public:
	std::string name;
	DataBase(std::string name);
	void addTable();
	void removeTable();
	void deleteDataBase();
};

