#include "Header.h"
#pragma once

Document_10_Version_1_Reader::Document_10_Version_1_Reader() {
	this->number = 10;
	this->version = 1;
}

void  Document_10_Version_1_Reader::read(std::ifstream &f, unsigned int address, int count) {
	

	f.seekg(address);
	std::clog << "Document_10_Version_1_Reader::read  this->number = " << this->number << ", this->version = " << this->version << std::endl;

	// Check document header
	bool isDocCorrect = this->isDocumentCorrect(f, this->number, this->version);
	count -= sizeof(this->number) + sizeof(this->version);

	if (isDocCorrect) {

		// Read document body
		// Get number of objects
		unsigned int objectCount;
		f.read((char *)&objectCount, sizeof(unsigned int));
		count -= sizeof(objectCount);

		// Read objects
		unsigned int i = 0;
		while (count >= 0 && i < objectCount) {
			Node object = this->readSingleObject(f, count);

			if (count >= 0) {
				// Add Object to Model
				Model::addObject(&object);
			}

			i++;
		}
	}
	else {
		std::clog << "ERROR - Document " << this->number << "[" << this->version << "] " << std::endl;
	}
}

Node Document_10_Version_1_Reader::readSingleObject(std::ifstream &f, int &count) {
	unsigned int id; // Node's id
	double x, y, z; // Node's coordinate

	f.read((char *)&id, sizeof(unsigned int));
	f.read((char *)&x, sizeof(double));
	f.read((char *)&y, sizeof(double));
	f.read((char *)&z, sizeof(double));

	count -= sizeof(id) + sizeof(x) + sizeof(y) + sizeof(z);

	return Node(id, "", x, y, z);
}