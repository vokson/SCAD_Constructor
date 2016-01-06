#pragma once

class Member : public Instance {
protected:
	/* Abstract fucntion to make class polymorphous */
	void abstractFunction();

public:
	unsigned int id; /* Номер элемента */
	unsigned int node1; /* Номер первого узла */
	unsigned int node2; /* Номер второго узла */
	double betaAngle; /* Угол поворота элемента */

	std::string name; /* Имя элемента */
	std::string section; /* Жесткость */

	unsigned short pin1; /* Шарнир в первом узле */
	unsigned short pin2; /* Шарнир во втором узле */

	/* Default constructor*/
	Member(unsigned int id, std::string name, unsigned int node1, unsigned int node2,
		unsigned short pin1, unsigned short pin2, double betaAngle, std::string section);
};