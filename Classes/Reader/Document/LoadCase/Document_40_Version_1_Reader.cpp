#include "Header.h"
#pragma once

Document_40_Version_1_Reader::Document_40_Version_1_Reader() {
	this->number = 40;
	this->version = 1;
	this->name = "LOAD CASES";
}

Instance* Document_40_Version_1_Reader::readSingleObject(std::ifstream &f, int &count) {
	unsigned short id; //Load case id
	unsigned short nameLength; // Count of bytes in name
	unsigned short descriptionLength; // Count of bytes in description
	char charName[100]; // Load case's name
	char charDescription[100]; // Load case's description
	unsigned short factorCount; // Count of coefficients for Mass Matrix
	std::vector<massMatrixFactor> factors; // Vector of factors (struct)

	f.read((char *)&id, sizeof(id));

	// Name
	f.read((char *)&nameLength, sizeof(nameLength));
	f.read(charName, nameLength);
	std::string stringName(charName);

	// Description
	f.read((char *)&descriptionLength, sizeof(descriptionLength));
	f.read(charDescription, descriptionLength);
	std::string stringDescription(charDescription); // Description

	f.read((char *)&factorCount, sizeof(factorCount));

	// Read factors
	unsigned short maxTargetLoadCase = 0;
	for (int i = 0; i < factorCount; i++) {
		massMatrixFactor element;
		f.read((char *)&element.targetLoadCase, sizeof(element.targetLoadCase));
		f.read((char *)&element.factor, sizeof(element.factor));
		factors.push_back(element);

		if (element.targetLoadCase > maxTargetLoadCase) {
			maxTargetLoadCase = element.targetLoadCase;
		}
	}

	// Vector of factors in SCAD format
	// masses[0] = 0
	// masses[1] - correspond to Load Case No.1
	std::vector<double> masses(maxTargetLoadCase + 1, 0.0);

	// Apply factors
	for (int i = 0; i < factors.size(); i++) {
		masses[factors[i].targetLoadCase] = factors[i].factor;
	}

	std::clog << "   ID = " << id << "  NAME='" << stringName << "' DESCRIPTION='" << stringDescription << "'" << std::endl;
	std::clog << "   MASSES (";
	for (int i = 0; i < factors.size(); i++) {
		std::clog << factors[i].targetLoadCase << ": " << factors[i].factor;
		if (i < (factors.size() - 1)) {
			std::clog << ", ";
		}
	}
	std::clog << ")" << std::endl;

	count -= sizeof(id) + sizeof(nameLength) + nameLength + sizeof(descriptionLength) + descriptionLength;
	count -= sizeof(factorCount) + factorCount * (sizeof(unsigned short) + sizeof(double));

	LoadCase* object = new LoadCase(id, stringName, stringDescription, masses);

	return object;
}