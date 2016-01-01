#include "stdafx.h"
#include <fstream>
#include <ctime>
#include <string>
//#include "FileReader.h"
#include "API/Include/ScadAPIX.hxx"

#include "IAnimal.h"
#include "AnimalFactory.h"
#pragma comment(lib, "API/Lib/32/SCADAPIX.lib" ) 


std::string fileName; /*Name of file*/

/*
Arguments format
[1] - File Name
*/

int main(int argc, char* argv[])
{
	// ѕолучаем аргументы - им€ файла с Model Data
	if (argc > 1)// если передаем аргументы, то argc будет больше 1(в зависимости от кол-ва аргументов)
	{
		//Redirect std::clog to file
		std::ofstream logFile("log.txt");
		std::clog.rdbuf(logFile.rdbuf());

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

		// Take arguments
		fileName = std::string(argv[1]);
		std::clog << "Read file '" << fileName << "'" << std::endl;

		// Create file reader
		//FileReader fileReader = FileReader();
		
		// Check file
		/*if (!fileReader.isFileCorrect(fileName)) {
			return 0;
		}*/

		// Read file
		//fileReader.read();

		IAnimal *pAnimal = AnimalFactory::Get()->CreateAnimal("Horse");
		if (pAnimal)
		{
			std::cout << "Your animal has " << pAnimal->GetNumberOfLegs() << " legs." << std::endl;
			std::cout << "Your animal says : ";
			pAnimal->Speak();
		}

	}
	else
	{
		std::cout << "Arguments are wrong !!!" << std::endl;
		std::cout << std::endl;
		std::cout << "Arguments format:" << std::endl;
		std::cout << "   [1] - File Name" << std::endl;
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


	//APICode Code;
	//Code = ApiWriteProject(handle, "TestNewProject.spr");
	//if (Code != APICode_OK) { APIPhrase(handle, Code); }
	//ApiRelease(&handle);

}

