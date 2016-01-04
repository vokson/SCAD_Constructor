#pragma once

struct docDescription {
	unsigned short number;   // Number of document
	unsigned short version;   // Version of document
	unsigned int address; // Address of document's begin in file
	unsigned int count; // Count of bytes in document
};

// Reader implementations
class File_Version_1_Reader : public Reader
{
private:
	std::vector<docDescription> documents; // Vector of docs' descriptions

	void readAllDocumentsDescription(std::ifstream &f, unsigned int address);
	docDescription readSingleDocumentDescription(std::ifstream &f);
	void readAllDocumentsBody(std::ifstream &f);
	

public:
	void read(std::ifstream &f, unsigned int address, int count);
	static Reader * __stdcall Create() { return new File_Version_1_Reader(); }
};