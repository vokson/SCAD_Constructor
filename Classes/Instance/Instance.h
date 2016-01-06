#pragma once

class Instance {
protected:
	virtual void abstractFunction() = 0;
};

//typedef Instance* (__stdcall *CreateInstanceFn)(void);
