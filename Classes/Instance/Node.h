#pragma once

class Node : public Instance {
public:
	int id; /* ����� ���� */
	std::string name; /* ��� ���� */
	double x, y, z; /* ���������� ���� */

	/* Default constructor*/
	Node(unsigned int id, std::string name, double x, double y, double z);
	void abstractFunction();
};