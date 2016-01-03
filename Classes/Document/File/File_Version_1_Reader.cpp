#include <Header.h>
#pragma once

/* Read file */
void File_Version_1_Reader::read(std::ifstream &f, unsigned int address, int count) {

	// Get description address
	unsigned int descriptionAddress;
	f.seekg(address);
	f.read((char *)&descriptionAddress, sizeof(unsigned int));

	// Read docs' descriptions
	this->readAllDocumentsDescription(f, descriptionAddress);

	// Read all documents
	this->readAllDocumentsBody(f);
}

/*
* Add descriptions of Documents into array
*
* @param ifstream f Stream of file
* @param u_int address Start address of docs' description
*/
void File_Version_1_Reader::readAllDocumentsDescription(std::ifstream &f, unsigned int address) {
	// Goto start address
	f.seekg(address);

	// Read docs
	bool isFinalDocument = false;

	while (!isFinalDocument) {

		// Create new document description
		docDescription doc;
		doc = this->readSingleDocumentDescription(f);

		if (doc.number > 0) {
			// Document isn't final
			this->documents.push_back(doc);
		}
		else {
			// Document is final
			isFinalDocument = true;
		}
	}
}

/*
* Read document description
*
* @param ifstream f Stream of file
*
* @return bool TRUE - non-ZERO doc, FALSE - ZERO doc
*/
docDescription File_Version_1_Reader::readSingleDocumentDescription(std::ifstream &f) {

	docDescription doc;

	//std::clog << "Offset = " << f.tellg() << std::endl;

	// Read doc number
	f.read((char *)&doc.number, sizeof(unsigned short));

	if (doc.number > 0) {

		// Apply properties
		f.read((char *)&doc.version, sizeof(unsigned short));
		f.read((char *)&doc.address, sizeof(unsigned int));
		f.read((char *)&doc.count, sizeof(unsigned int));
	}

	return doc;
}

/* Read all documents' bodies
*
* @param ifstream f Stream of file
*/
void File_Version_1_Reader::readAllDocumentsBody(std::ifstream &f) {

	while (!this->documents.empty())
	{
		// Create new document description
		docDescription doc = documents.back();

		std::clog << "DOC " << doc.number << "[" << doc.version << "]  " << doc.address << " - " << doc.count << std::endl;

		// Read document
		DocumentReader *docReader = DocumentReaderFactory::Get()->CreateDocumentReader(doc.number, doc.version);

		if (docReader) {
			docReader->read(f, doc.address, doc.count);
		}
		else {
			std::clog << "ERROR - Incorrect document(" << doc.number << ") version(" << doc.version << ")" << std::endl;
		}
		

		this->documents.pop_back();
	}
}