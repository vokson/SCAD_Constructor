#pragma once

class FileFormatChecker {
public:
	/* 	Check if File Header correct or not	*/
	/* Header format:
		(12)	string		"*MODEL_DATA"
		(2)		u_short		Version of file
	*/
	static bool FileFormatChecker::isFileCorrect(std::string fileName,
		unsigned short &fileVersion, unsigned int &offset, unsigned int &count); 
};