#include "Header.h"
#pragma once

Document_10_Version_1_Reader::Document_10_Version_1_Reader() {
	this->number = 10;
	this->version = 1;
	this->name = "NODES";
}

Instance* Document_10_Version_1_Reader::readSingleObject(std::ifstream &f, int &count) {
	unsigned int id; // Node's id
	double x, y, z; // Node's coordinate

	f.read((char *)&id, sizeof(unsigned int));
	f.read((char *)&x, sizeof(double));
	f.read((char *)&y, sizeof(double));
	f.read((char *)&z, sizeof(double));

	std::clog << Timer::get() << "ID = " << id << "  COORDINATES (" << x << ", " << y << ", " << z << ")" << std::endl;

	count -= sizeof(id) + sizeof(x) + sizeof(y) + sizeof(z);

	Node* object = new Node(id, "", x, y, z);

	return object;
}