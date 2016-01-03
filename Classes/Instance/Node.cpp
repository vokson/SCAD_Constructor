#include "Header.h"
#pragma once

Node::Node (unsigned int id, std::string name, double x, double y, double z) {
	this->id = id;
	this->name = name;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Node::abstractFunction() {

}
