#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#pragma once

struct docDescription { 
	unsigned int number;   // Number of document
	unsigned int address; // Address of document's begin in file
	unsigned int count; // Count of bytes in document
};

class FileReader {
private:
	unsigned short fileVersion; // Version of file
	std::string fileName; //Name of file
	std::vector<docDescription> documents; // Vector of docs' descriptions
	
	/* Read file. Version 1.
		File format:
	(14)	mixed		File Header
	(4)		u_int		Address of documents' description

	(..)				Documents' body

	* EACH DOCUMENT DESCRIPTION *
	(4)		u_int		Document number > 0
	(4)		u_int		Address of document
	(4)		u_int		Size of document in bytes

	(4)		u_int		End of file - 4 zero bytess
	*/
	void readFileVersion_1() {
		// Open file
		std::ifstream f(this->fileName.c_str(), std::ios::binary);

		if (f.good()) {
			unsigned int descriptionAddress;

			f.seekg(14);
			f.read((char *)&descriptionAddress, sizeof(unsigned int));

			// Read description
			f.seekg(descriptionAddress);

			unsigned int docNumber = 1;
			while (docNumber > 0) {
				f.read((char *)&docNumber, sizeof(unsigned int));
				if (docNumber > 0) {

					// Create new document description
					docDescription doc;

					// Apply properties
					doc.number = docNumber;
					f.read((char *)&doc.address, sizeof(unsigned int));
					f.read((char *)&doc.count, sizeof(unsigned int));

					// Add document to vector
					this->documents.push_back(doc);
				}
			}

			// Read all documents
			while (!documents.empty())
			{
				// Create new document description
				docDescription doc;
				doc = documents.back();

				std::clog << "DOC " << doc.number << " - " << doc.address << " - " << doc.count << std::endl;

				documents.pop_back();
			}
		}
	}

public:
	/* 	Check if File Header correct or not	*/
	/* Header format:
		(12)	string		"*MODEL_DATA"
		(2)		u_short		Version of file
	*/
	bool isFileCorrect(std::string fileName) {
		// Try to open file
		std::ifstream f(fileName.c_str(), std::ios::binary);

		if (f.good()) {
			// Check format name
			char fileHeader[13];
			fileHeader[12] = '\0';
			f.read(fileHeader, 12);

			char correctFileHeader[] = "*MODEL_DATA*";
			
			// If format correct
			if (! strcmp(fileHeader, correctFileHeader)) {
				
				// Set file name
				this->fileName = fileName;

				// Check version 
				f.read((char *)&this->fileVersion, sizeof(unsigned short));
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

	/* Read file */
	void read() {
		// Read file as per version
		switch (this->fileVersion) {
		case 1:
			this->readFileVersion_1();
			break;
		default:
			std::clog << "ERROR - Incorrect file version("<< this->fileVersion << ")" << std::endl;
		}
	}
};