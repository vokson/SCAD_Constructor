#pragma once

class Instance {
public:
	virtual void abstractFunction() = 0;
};

//typedef Instance* (__stdcall *CreateInstanceFn)(void);
