#include "Header.h"
#pragma once


/* Default constructor*/
Load::Load(unsigned short loadCase, unsigned int number, unsigned short loadType, unsigned short loadDirection, std::vector <double> data) {
	this->loadCase = loadCase;
	this->number = number;
	this->loadType = loadType;
	this->loadDirection = loadDirection;
	this->data = data;
}

void Load::abstractFunction() {

}
