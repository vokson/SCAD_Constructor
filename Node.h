#pragma once
#include <string>

class Node {
public:
	int id; /* ����� ���� */
	std::string name; /* ��� ���� */
	double x, y, z; /* ���������� ���� */

	/* Default constructor*/
	Node (int id, std::string name, double x, double y, double z) {
		this->id = id;
		this->name = name;
		this->x = x;
		this->y = y;
		this->z = z;
	}
};