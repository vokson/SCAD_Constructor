#include "Header.h"
#pragma once

/* Mass Matrix Constructor*/
LoadCase::LoadCase(unsigned short id, std::string name, std::string type, std::vector <double> masses) {
	this->id = id;
	this->name = name;
	this->type = type;
	this->masses = masses;
}

void LoadCase::abstractFunction() {

}