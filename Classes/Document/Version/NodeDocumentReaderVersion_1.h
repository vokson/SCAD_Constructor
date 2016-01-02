#include <string>
#include <iostream>
#pragma once

// DocumentReader implementations
class NodeDocumentReaderVersion_1 : public DocumentReader
{
public:
	void read(unsigned int address, unsigned int count) {
		std::clog << "NodeDocumentReaderVersion_1: address - " << address << ", count - " << count << std::endl;
	}

	static DocumentReader * __stdcall Create() { return new NodeDocumentReaderVersion_1(); }
};