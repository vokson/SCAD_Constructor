#pragma once
#include <string>

class Member {
public:
	int id; /* ����� �������� */
	int node1; /* ����� ������� ���� */
	int node2; /* ����� ������� ���� */
	double betaAngle; /* ���� �������� �������� */

	std::string name; /* ��� �������� */
	std::string section; /* ��������� */

	int pin1; /* ������ � ������ ���� */
	int pin2; /* ������ �� ������ ���� */

	/* Default constructor*/
	Member(int id, int node1, int node2, int pin1, int pin2,  int betaAngle, std::string section, std::string name) {
		this->id = id;

		this->node1 = node1;
		this->pin1 = pin1;

		this->node2 = node2;
		this->pin2 = pin2;

		this->betaAngle = betaAngle;
		this->name = name;
		this->section = section;
	}
};