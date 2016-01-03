#pragma once

// DocumentReader implementations
class Document_10_Version_1_Reader : public DocumentReader
{
public:
	void read(std::ifstream &f, unsigned int address, unsigned int count);
	static DocumentReader * __stdcall Create() { return new Document_10_Version_1_Reader(); }
};