#pragma once

// DocumentReader implementations
class Document_10_Version_1_Reader : public DocumentReader
{
public:

	Document_10_Version_1_Reader();

	Instance *readSingleObject(std::ifstream &f, int &count);

	static Reader * __stdcall Create() { return new Document_10_Version_1_Reader(); }
};