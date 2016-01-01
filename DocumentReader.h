#include <fstream>
//#include "Doc10Reader.h"
#pragma once

/* Base class for document readers */
class DocumentReader {
//public:

	/* Create document reader by number of document */
	//DocumentReader* makeDocumentReaderByNumber(unsigned int number) {
	//	switch (number) {
	//		// Nodes
	//	case 10:
	//		return new Doc10Reader();
	//	default:
	//		std::clog << "ERROR - Can NOT read document number " << number << std::endl;
	//	}
	//}

	virtual void read( unsigned int address, unsigned int count) = 0;
};



