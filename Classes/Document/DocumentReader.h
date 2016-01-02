#pragma once

class DocumentReader
{
public:
	virtual void read(unsigned int address, unsigned int count) = 0;
};

typedef DocumentReader* (__stdcall *CreateDocumentReaderFn)(void);



