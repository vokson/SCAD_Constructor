#include "Header.h"
#pragma once

Document_50_Version_1_Reader::Document_50_Version_1_Reader() {
	this->number = 50;
	this->version = 1;
	this->name = "LOADS";
}

Instance* Document_50_Version_1_Reader::readSingleObject(std::ifstream &f, int &count) {
	unsigned short loadCase; /* Номер загружения */
	unsigned short loadType; /* Тип нагрузки в формате SCAD */
	unsigned short loadDirection; /* Направление нагрузки */
	unsigned int id; /* Номер узла или элемента, к которым приложена нагрузка */
	unsigned short dataCount; /* Кол-во элементов в data */
	std::vector <double> data; /* Массив значений нагрузок */

	unsigned short type; /* Тип нагрузки в формате файла*/
	unsigned short coorSystem; /* Тип системы координат в формате файла */


	f.read((char *)&loadCase, sizeof(loadCase));
	f.read((char *)&id, sizeof(id));
	f.read((char *)&type, sizeof(type));
	f.read((char *)&coorSystem, sizeof(coorSystem));
	f.read((char *)&loadDirection, sizeof(loadDirection));
	f.read((char *)&dataCount, sizeof(dataCount));

	// Set load type
	switch (type) {
		// Nodal concentrated load
	case 0:
		loadType = 0;
		break;
		// Member concentrated load
	case 1:
		if (coorSystem == 0) { loadType = 15; }
		if (coorSystem == 1) { loadType = 5; }
		break;
		// Member distributed load
	case 2:
		if (coorSystem == 0) { loadType = 17; }
		if (coorSystem == 1) { loadType = 7; }
		break;

	default:
		std::clog << "ERROR - Incorrect load type = " << type << std::endl;
	}

	// Read array with data
	for (int i = 0; i < dataCount; i++) {
		double value;
		f.read((char *)&value, sizeof(value));

		data.push_back(value);
	}

	std::clog << "   LOAD CASE [" << loadCase << "] TO ID " << id << ", COORDINATE SYSTEM = " << this->getCoorSystemName(coorSystem) << ", TYPE = " << type << ", " << this->getDirectionName(loadDirection) << std::endl;
	std::clog << "   VALUES (";
	for (int i = 0; i < data.size(); i++) {
		std::clog << data[i];
		if (i < (data.size() - 1)) {
			std::clog << ", ";
		}
	}
	std::clog << ")" << std::endl;

	count -= sizeof(loadCase) + sizeof(id) + sizeof(type) + sizeof(coorSystem) + sizeof(loadDirection);
	count -= sizeof(dataCount) + dataCount * sizeof(double);

	Load* object = new Load(loadCase, id, loadType, loadDirection, data);

	return object;
}

std::string Document_50_Version_1_Reader::getCoorSystemName(unsigned short id) {
	switch (id) {
	case 0:
		return "Global"; break;
	case 1:
		return "Local"; break;
	default:
		return "Error";
	}
}

std::string Document_50_Version_1_Reader::getDirectionName(unsigned short id) {
	switch (id) {
	case 1:
		return "FX"; break;
	case 2:
		return "FY"; break;
	case 3:
		return "FZ"; break;
	case 4:
		return "MX"; break;
	case 5:
		return "MY"; break;
	case 6:
		return "MZ"; break;

	default:
		return "Error";
	}
}