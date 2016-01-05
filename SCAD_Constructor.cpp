#include "Header.h"

// Variables
std::string fileName; /* Name of file */
unsigned short fileVersion; /* Version of file */
unsigned int offset; /* Start offset for file reader */
unsigned int count; /* Count of bytes from offset to end of file */

/*
Arguments format
[1] - File Name
*/

// Functions
void wrongArgumentsFeedback();

int main(int argc, char* argv[])
{
	//Redirect std::clog to file
	std::ofstream logFile("log.txt");
	std::clog.rdbuf(logFile.rdbuf());

	// Получаем аргументы - имя файла с Model Data
	// если передаем аргументы, то argc будет больше 1(в зависимости от кол-ва аргументов)
	if (argc > 1) {
	
		
		// Take arguments
		fileName = std::string(argv[1]);

		std::clog << "   Read file '" << fileName << "'" << std::endl;

		// Check file
		if (!FileReader::isFileCorrect(fileName, fileVersion, offset, count)) {
			return 0;
		}
		
		// Open file
		std::ifstream f(fileName.c_str(), std::ios::binary);

		if (f.good()) {

			// Create file reader
			Reader *fileReader = ReaderFactory::Get()->CreateFileReader(fileVersion);

			// Read file
			if (fileReader)	{
				// Read binary data file into Model
				fileReader->read(f, offset, count);

				// Write Model to file
				Model::create("Test");
			}
			else {
				std::clog << "ERROR - Incorrect file version(" << fileVersion << ")" << std::endl;
			}
			
		}

	} 	else	{
		wrongArgumentsFeedback();
	}

	return 0;
}

/* Function provides feedback in case of wrong arguments passed */
void wrongArgumentsFeedback() {
	std::cout << "Arguments are wrong !!!" << std::endl;
	std::cout << std::endl;
	std::cout << "Arguments format:" << std::endl;
	std::cout << "   [1] - File Name" << std::endl;
}


