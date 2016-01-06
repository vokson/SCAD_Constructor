#pragma once

// DocumentReader implementations
class Document_40_Version_1_Reader : public DocumentReader
{
public:

	Document_40_Version_1_Reader();

	Instance *readSingleObject(std::ifstream &f, int &count);

	static Reader * __stdcall Create() { return new Document_40_Version_1_Reader(); }
};

struct massMatrixFactor {
	unsigned short targetLoadCase; // Masses to be taken from the Load Case
	double factor; // and multiplied by the coefficient
};