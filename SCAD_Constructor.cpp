#include "SCAD_Constructor.h"
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

int main(int argc, char* argv[])
{
	//Redirect std::clog to file
	std::ofstream logFile("log.txt");
	std::clog.rdbuf(logFile.rdbuf());

	prepareLogFile();

	// ѕолучаем аргументы - им€ файла с Model Data
	// если передаем аргументы, то argc будет больше 1(в зависимости от кол-ва аргументов)
	if (argc > 1) {
	
		
		// Take arguments
		fileName = std::string(argv[1]);
		std::clog << "Read file '" << fileName << "'" << std::endl;

		// Check file
		if (!FileFormatChecker::isFileCorrect(fileName, fileVersion, offset, count)) {
			return 0;
		}
		
		// Open file
		std::ifstream f(fileName.c_str(), std::ios::binary);

		if (f.good()) {

			// Create file reader
			DocumentReader *fileReader = DocumentReaderFactory::Get()->CreateFileReader(fileVersion);

			// Read file
			if (fileReader)	{
				fileReader->read(f, offset, count);
			}
			else {
				std::clog << "ERROR - Incorrect file version(" << fileVersion << ")" << std::endl;
			}
			
		}

	} 	else	{
		wrongArgumentsFeedback();
	}

	system("pause");
	return 0;


	//ScadAPI	handle(NULL);
	////UINT n, i, j, Node[4], Elem[4];
	////double Size[6];
	//const static UnitsAPI Un[3] = { { "m", 1 },{ "cm", 100 },{ "T", 1 } };

	//if (ApiCreate(&handle) != APICode_OK) ApiMsg("Error");  //  создание объекта API и контроль
	//if (ApiClear(handle) != APICode_OK) ApiMsg("Error");    //  после открыти€ можно не делать
	//if (ApiSetLanguage(handle, 1) != APICode_OK) ApiMsg("Error");
	//ApiSetName(handle, "TestNewProject");
	//ApiSetUnits(handle, Un);
	//if (ApiSetTypeSchema(handle, 5) != APICode_OK) ApiMsg("Error");

	////Prepare Model
	//Model model = Model();
	//
	//// Nodes
	//model.createNodes(handle);

	//// Elements
	//model.createMembers(handle);

	//// Restraints
	//model.createRestraints(handle);

	//// Load cases
	//model.createLoadCases(handle);

	//// Load cases
	//model.createLoads(handle);


	/*APICode Code;
	Code = ApiWriteProject(handle, "TestNewProject.spr");
	if (Code != APICode_OK) { APIPhrase(handle, Code); }
	ApiRelease(&handle);*/

}

/* Function to prepare log file */
void prepareLogFile() {
	

	//Write Date&Tiem to Log
	time_t t = std::time(0);   // get time now
	struct tm * now = localtime(&t);
	std::clog << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday << " "
		<< now->tm_hour << ":"
		<< now->tm_min << ":"
		<< now->tm_sec
		<< std::endl;
}

/* Function provides feedback in case of wrong arguments passed */
void wrongArgumentsFeedback() {
	std::cout << "Arguments are wrong !!!" << std::endl;
	std::cout << std::endl;
	std::cout << "Arguments format:" << std::endl;
	std::cout << "   [1] - File Name" << std::endl;
}


