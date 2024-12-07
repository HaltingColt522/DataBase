#pragma once
#include "dataBase.hpp"
#include <iostream>

template <typename columnType> class Column
{
public:
	Column(
		unsigned int columnID,
		std::string columnHeader,
		bool isLeadingColumn);

	unsigned int columnID;
	std::string columnHeader;
	bool isLeadingColumn;
	void printColumn();
	std::string getTypeName();
};

template <typename columnType>
Column<columnType>::Column(
	unsigned int columnID,
	std::string columnHeader,
	bool isLeadingColumn)
	: columnID(columnID),
	columnHeader(columnHeader),
	isLeadingColumn(isLeadingColumn){}

template <typename columnType>
std::string Column<columnType>::getTypeName() {
	if (std::is_same<columnType, int>::value) return "int";
	else if (std::is_same<columnType, float>::value) return "float";
	else if (std::is_same<columnType, double>::value) return "double";
	else if (std::is_same<columnType, bool>::value) return "bool";
	else if (std::is_same<columnType, std::string>::value) return "std::string";
	return "unknown";
}

template <typename columnType>
void Column<columnType>::printColumn() {
	std::cout << std::boolalpha;
	std::cout << columnHeader << "|" <<
		columnID << "|" <<
		getTypeName() << "|" <<
		isLeadingColumn << "\n";
}