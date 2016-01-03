#pragma once

class DocumentReader
{
protected:
	unsigned short number; // Number of document
	unsigned short version; // Version of document

	bool isDocumentCorrect(std::ifstream &f, unsigned short correctNumber, unsigned short correctVersion);

public:
	virtual void read(std::ifstream &f, unsigned int address, int count) = 0;
};

typedef DocumentReader* (__stdcall *CreateDocumentReaderFn)(void);