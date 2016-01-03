#pragma once

class Node : public Instance {
public:
	int id; /* Номер узла */
	std::string name; /* Имя узла */
	double x, y, z; /* Координаты узла */

	/* Default constructor*/
	Node(unsigned int id, std::string name, double x, double y, double z);
	void abstractFunction();
};