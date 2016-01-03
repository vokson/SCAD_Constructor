#include "Header.h"

/* 
 * Check if doc's number and version correspond to description
 *
 * @return bool Success or Not
 */
bool DocumentReader::isDocumentCorrect(std::ifstream &f,
	unsigned short correctNumber, unsigned short correctVersion) {

	unsigned short number, version;

	f.read((char *)&number, sizeof(unsigned short));
	f.read((char *)&version, sizeof(unsigned short));

	if (number == correctNumber && version == correctVersion) {
		return true;
	}

	return false;
}