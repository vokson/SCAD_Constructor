#pragma once
#include <string>

class Restraint {
public:
	int id; /* Номер узла */
	int fix; /* Закрепление в узле */
			 
	/* Default constructor*/
	Restraint (int id, int fix) {
		this->id = id;
		this->fix = fix;
	}
};