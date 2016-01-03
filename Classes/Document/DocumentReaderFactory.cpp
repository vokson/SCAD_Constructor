#include "Header.h"
#pragma once

/*
Document Reader Factory constructor.
Register the types of DocumentReader here.
*/
DocumentReaderFactory::DocumentReaderFactory()
{
	Register("Document10_1", &Document_10_Version_1_Reader::Create);
	Register("File_1", &File_Version_1_Reader::Create);
}

void DocumentReaderFactory::Register(const std::string &documentReaderName, CreateDocumentReaderFn pfnCreate)
{
	m_FactoryMap[documentReaderName] = pfnCreate;
}

DocumentReader *DocumentReaderFactory::CreateReader(const std::string &documentReaderName)
{
	FactoryMap::iterator it = m_FactoryMap.find(documentReaderName);
	if (it != m_FactoryMap.end())
		return it->second();
	return NULL;
}

DocumentReader *DocumentReaderFactory::CreateDocumentReader(const unsigned int number, const unsigned int version)
{
	return this->CreateReader("Document" + boost::lexical_cast<std::string>(number) + "_" + boost::lexical_cast<std::string>(version));
}

DocumentReader *DocumentReaderFactory::CreateFileReader(const unsigned int version)
{
	return this->CreateReader("File_" + boost::lexical_cast<std::string>(version));
}