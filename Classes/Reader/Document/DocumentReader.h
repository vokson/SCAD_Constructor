#pragma once

class DocumentReader : public Reader
{
protected:
	unsigned short number; // Number of document
	unsigned short version; // Version of document
	std::string name; // Name of document

	bool isDocumentCorrect(std::ifstream &f, unsigned short correctNumber, unsigned short correctVersion);
	virtual Instance* readSingleObject(std::ifstream &f, int &count) = 0;

public:
	void read(std::ifstream &f, unsigned int address, int count);
};