#include <fstream>
#include <iostream>
#include "DocumentReader.h"
#pragma once

/* Document 10 (Nodes) Reader */
class Doc10Reader : public DocumentReader {
public:
	
	void read( unsigned int address, unsigned int count) {
		std::clog << "DOC 10 Reader (inside)" << std::endl;
	}
};