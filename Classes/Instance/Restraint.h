#pragma once

class Restraint : public Instance {
protected:
	/* Abstract fucntion to make class polymorphous */
	void abstractFunction();

public:
	unsigned int id; /* ����� ���� */
	unsigned short fix; /* ����������� � ���� */
			 
	/* Default constructor*/
	Restraint(unsigned int id, unsigned short fix);
};