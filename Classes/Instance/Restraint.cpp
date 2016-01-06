#include "Header.h"
#pragma once

/* Default constructor*/
Restraint::Restraint(unsigned int id, unsigned short fix) {
	this->id = id;
	this->fix = fix;
}

void Restraint::abstractFunction() {

}