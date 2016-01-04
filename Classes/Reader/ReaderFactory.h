#pragma once

/* Factory for creation of Reader objects */
class ReaderFactory
{
private:
	ReaderFactory();
	ReaderFactory(const ReaderFactory &) { }
	ReaderFactory &operator=(const ReaderFactory &) { return *this; }

	typedef std::map<std::string, CreateReaderFn> FactoryMap;
	FactoryMap m_FactoryMap;
public:
	~ReaderFactory() { m_FactoryMap.clear(); }

	static ReaderFactory *Get()
	{
		static ReaderFactory instance;
		return &instance;
	}

	void Register(const std::string &readerName, CreateReaderFn pfnCreate);
	Reader *CreateReader(const std::string &readerName);
	Reader *CreateDocumentReader(const unsigned int number, const unsigned int version);
	Reader *CreateFileReader(const unsigned int version);
};