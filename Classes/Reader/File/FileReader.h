#pragma once

class FileReader : public Reader
{

public:
	static bool isFileCorrect(std::string fileName,
		unsigned short &fileVersion, unsigned int &offset, unsigned int &count);

	virtual void read(std::ifstream &f, unsigned int address, int count) = 0;
};