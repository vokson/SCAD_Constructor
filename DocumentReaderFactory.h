#include <iostream>
#include "DocumentReader.h"
#include "Doc10Reader.h"
#pragma once

class DocumentReaderFactory {
public:
	/* Create document reader by number of document */
	DocumentReader* makeDocumentReaderByNumber(unsigned int number) {
		switch (number) {
			// Nodes
		case 10:
			return new Doc10Reader();
		default:
			std::clog << "ERROR - Can NOT read document number " << number << std::endl;
		}
	}
};