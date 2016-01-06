#include "Header.h"
#pragma once

/* Default constructor*/
Member::Member(unsigned int id, std::string name, unsigned int node1, unsigned int node2,
	unsigned short pin1, unsigned short pin2, double betaAngle, std::string section) {
	this->id = id;

	this->node1 = node1;
	this->node2 = node2;

	this->pin1 = pin1;
	this->pin2 = pin2;

	this->betaAngle = betaAngle;
	this->name = name;
	this->section = section;
}

void Member::abstractFunction() {

}
