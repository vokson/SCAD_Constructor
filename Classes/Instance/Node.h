#pragma once

class Node : public Instance {
protected:
	/* Abstract fucntion to make class polymorphous */
	void abstractFunction();
public:
	unsigned int id; /* Номер узла */
	std::string name; /* Имя узла */
	double x, y, z; /* Координаты узла */

	/* Default constructor*/
	Node(unsigned int id, std::string name, double x, double y, double z);
};