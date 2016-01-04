#pragma once

class Reader {
public:
	virtual void read(std::ifstream &f, unsigned int address, int count) = 0;
};

typedef Reader* (__stdcall *CreateReaderFn)(void);