#include "Header.h"
#pragma once

Document_10_Version_1_Reader::Document_10_Version_1_Reader() {
	this->number = 10;
	this->version = 1;
	this->name = "NODES";
}

Instance* Document_10_Version_1_Reader::readSingleObject(std::ifstream &f, int &count) {
	unsigned int id; // Node's id
	unsigned short nameLength; // Count of bytes in name
	double x, y, z; // Node's coordinate
	char charName[100]; // Node's name
	

	f.read((char *)&id, sizeof(unsigned int));
	f.read((char *)&x, sizeof(double));
	f.read((char *)&y, sizeof(double));
	f.read((char *)&z, sizeof(double));
	f.read((char *)&nameLength, sizeof(unsigned short));
	f.read(charName, nameLength);

	std::string stringName(charName); // Node's name

	std::clog << "   ID = " << id << "  COORDINATES (" << x << ", " << y << ", " << z << ") NAME='" << stringName << "'" << std::endl;

	count -= sizeof(id) + sizeof(x) + sizeof(y) + sizeof(z);

	Node* object = new Node(id, stringName, x, y, z);

	return object;
}