#include "Header.h"
#pragma once

Document_20_Version_1_Reader::Document_20_Version_1_Reader() {
	this->number = 20;
	this->version = 1;
	this->name = "MEMBERS";
}

Instance* Document_20_Version_1_Reader::readSingleObject(std::ifstream &f, int &count) {
	unsigned int id; // Node's id
	unsigned int idNode1; // Node 1 id
	unsigned int idNode2; // Node 2 id
	unsigned short pin1; // Pin 1
	unsigned short pin2; // Pin 2
	double betaAngle; // Rotational angle of local axies
	unsigned short nameLength; // Count of bytes in name
	char charName[100]; // Member's name
	unsigned short sectionLength; // Count of bytes in section
	char charSection[100]; // Member's section description
	

	f.read((char *)&id, sizeof(id));
	f.read((char *)&idNode1, sizeof(idNode1));
	f.read((char *)&idNode2, sizeof(idNode2));
	f.read((char *)&pin1, sizeof(pin1));
	f.read((char *)&pin2, sizeof(pin2));
	f.read((char *)&betaAngle, sizeof(betaAngle));
	f.read((char *)&sectionLength, sizeof(sectionLength));
	f.read(charSection, sectionLength);
	f.read((char *)&nameLength, sizeof(nameLength));
	f.read(charName, nameLength);

	std::string stringSection(charSection); // Member's section
	std::string stringName(charName); // Member's name

	//  " => |$id| [$betaAngle] $section *$name* <br/>";

	std::clog << "   (NODE1=" << idNode1 << ") =>" << pin1 << "=> (ID=" << id << ") <=" << pin2 << "<= (NODE2=" << idNode2 <<
		")  [" << betaAngle << "] " << " SECTION='" <<  stringSection << "' NAME='" << stringName << "'" << std::endl;

	count -= sizeof(id) + sizeof(idNode1) + sizeof(idNode2) + sizeof(pin1) + sizeof(pin2);
	count -= sizeof(betaAngle) + sizeof(nameLength) + sizeof(sectionLength) + nameLength + sectionLength;

	Member* object = new Member(id, stringName, idNode1, idNode2, pin1, pin2, betaAngle, stringSection);

	return object;
}