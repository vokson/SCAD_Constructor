#pragma once

// DocumentReader implementations
class Document_30_Version_1_Reader : public DocumentReader
{
public:

	Document_30_Version_1_Reader();

	Instance *readSingleObject(std::ifstream &f, int &count);

	static Reader * __stdcall Create() { return new Document_30_Version_1_Reader(); }
};