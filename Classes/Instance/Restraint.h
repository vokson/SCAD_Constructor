#pragma once
#include <string>

class Restraint {
public:
	int id; /* ����� ���� */
	int fix; /* ����������� � ���� */
			 
	/* Default constructor*/
	Restraint (int id, int fix) {
		this->id = id;
		this->fix = fix;
	}
};