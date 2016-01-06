#include "Header.h"
#pragma once

/*
Reader Factory constructor.
Register the types of Reader here.
*/
ReaderFactory::ReaderFactory()
{
	Register("Document10_1", &Document_10_Version_1_Reader::Create);
	Register("Document20_1", &Document_20_Version_1_Reader::Create);
	Register("Document30_1", &Document_30_Version_1_Reader::Create);
	Register("Document40_1", &Document_40_Version_1_Reader::Create);
	Register("Document50_1", &Document_50_Version_1_Reader::Create);
	Register("File_1", &File_Version_1_Reader::Create);
}

void ReaderFactory::Register(const std::string &readerName, CreateReaderFn pfnCreate)
{
	m_FactoryMap[readerName] = pfnCreate;
}

Reader *ReaderFactory::CreateReader(const std::string &readerName)
{
	FactoryMap::iterator it = m_FactoryMap.find(readerName);
	if (it != m_FactoryMap.end())
		return it->second();
	return NULL;
}

Reader *ReaderFactory::CreateDocumentReader(const unsigned int number, const unsigned int version)
{
	return this->CreateReader("Document" + boost::lexical_cast<std::string>(number) + "_" + boost::lexical_cast<std::string>(version));
}

Reader *ReaderFactory::CreateFileReader(const unsigned int version)
{
	return this->CreateReader("File_" + boost::lexical_cast<std::string>(version));
}