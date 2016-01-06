#include "Header.h"
#pragma once

Document_30_Version_1_Reader::Document_30_Version_1_Reader() {
	this->number = 30;
	this->version = 1;
	this->name = "RESTRAINTS";
}

Instance* Document_30_Version_1_Reader::readSingleObject(std::ifstream &f, int &count) {
	unsigned int id; // Node's id
	unsigned short fix; // Restraint

	f.read((char *)&id, sizeof(id));
	f.read((char *)&fix, sizeof(fix));

	std::clog << "   ID = " << id << "  FIX = " << fix << std::endl;

	count -= sizeof(id) + sizeof(fix);

	Restraint* object = new Restraint(id, fix);;

	return object;
}