#pragma once

// DocumentReader implementations
class Document_50_Version_1_Reader : public DocumentReader
{
private:
	std::string getCoorSystemName(unsigned short id);
	std::string getDirectionName(unsigned short id);
public:

	Document_50_Version_1_Reader();

	Instance *readSingleObject(std::ifstream &f, int &count);

	static Reader * __stdcall Create() { return new Document_50_Version_1_Reader(); }
};