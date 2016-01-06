#include "Header.h"
#pragma once

/* If number and version of document correspond to descritpted ones */
bool DocumentReader::isDocumentCorrect(std::ifstream &f, unsigned short correctNumber, unsigned short correctVersion) {
	unsigned short number, version;

	f.read((char *)&number, sizeof(unsigned short));
	f.read((char *)&version, sizeof(unsigned short));

	if (number == correctNumber && version == correctVersion) {
		return true;
	}

	return false;
}

/* Read document */
void  DocumentReader::read(std::ifstream &f, unsigned int address, int count) {
	f.seekg(address);
	

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
			Instance* object = this->readSingleObject(f, count);

			if (count >= 0) {
				// Add Object to Model
				Model::addObject(object);
			}

			i++;
		}
	}
	else {
		std::clog << "ERROR - Document " << this->number << "[" << this->version << "] " << std::endl;
	}
}