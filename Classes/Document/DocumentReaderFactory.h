#pragma once

/* Factory for creation of DocumentReader objects */
class DocumentReaderFactory
{
private:
	DocumentReaderFactory();
	DocumentReaderFactory(const DocumentReaderFactory &) { }
	DocumentReaderFactory &operator=(const DocumentReaderFactory &) { return *this; }

	typedef std::map<std::string, CreateDocumentReaderFn> FactoryMap;
	FactoryMap m_FactoryMap;
public:
	~DocumentReaderFactory() { m_FactoryMap.clear(); }

	static DocumentReaderFactory *Get()
	{
		static DocumentReaderFactory instance;
		return &instance;
	}

	void Register(const std::string &documentReaderName, CreateDocumentReaderFn pfnCreate);
	DocumentReader *CreateReader(const std::string &documentReaderName);
	DocumentReader *CreateDocumentReader(const unsigned int number, const unsigned int version);
	DocumentReader *CreateFileReader(const unsigned int version);
};