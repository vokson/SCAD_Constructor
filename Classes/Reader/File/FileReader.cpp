#include "Header.h"
#pragma once

bool FileReader::isFileCorrect(std::string fileName,
	unsigned short &fileVersion, unsigned int &offset, unsigned int &count) {

	// Try to open file
	std::ifstream f(fileName.c_str(), std::ios::binary);

	if (f.good()) {
		// Check format name
		char fileHeader[13];
		fileHeader[12] = '\0';
		f.read(fileHeader, 12);

		char correctFileHeader[] = "*MODEL_DATA*";

		// If format correct
		if (!strcmp(fileHeader, correctFileHeader)) {

			// Set offset
			offset = 14;

			// Set version 
			f.read((char *)&fileVersion, sizeof(unsigned short));

			// Get length of file:
			f.seekg(0, f.end);
			unsigned int length = f.tellg();
			//std::cout << "Length = " << length << std::endl;

			// Set count
			count = length - offset;

			f.close();

			return true;
		}
		else {
			f.close();
			std::clog << "ERROR - File is NOT file with model data" << std::endl;
			return false;
		}
	}
	else {
		f.close();
		std::clog << "ERROR - Can NOT open file" << std::endl;
		return false;
	}
}
