#pragma once

// DocumentReader implementations
class Document_10_Version_1_Reader : public DocumentReader
{
public:

	Document_10_Version_1_Reader();

	Node readSingleObject(std::ifstream &f, int &count);

	void read(std::ifstream &f, unsigned int address, int count);
	

	static DocumentReader * __stdcall Create() { return new Document_10_Version_1_Reader(); }
};