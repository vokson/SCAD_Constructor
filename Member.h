#pragma once
#include <string>

class Member {
public:
	int id; /* Номер элемента */
	int node1; /* Номер первого узла */
	int node2; /* Номер второго узла */
	double betaAngle; /* Угол поворота элемента */

	std::string name; /* Имя элемента */
	std::string section; /* Жесткость */

	int pin1; /* Шарнир в первом узле */
	int pin2; /* Шарнир во втором узле */

	/* Default constructor*/
	Member(int id, std::string name, int node1, int node2, int pin1, int pin2,  int betaAngle, std::string section) {
		this->id = id;

		this->node1 = node1;
		this->node2 = node2;

		this->pin1 = pin1;
		this->pin2 = pin2;

		this->betaAngle = betaAngle;
		this->name = name;
		this->section = section;
	}
};