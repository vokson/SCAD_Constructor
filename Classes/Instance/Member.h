#pragma once

class Member : public Instance {
protected:
	/* Abstract fucntion to make class polymorphous */
	void abstractFunction();

public:
	unsigned int id; /* ����� �������� */
	unsigned int node1; /* ����� ������� ���� */
	unsigned int node2; /* ����� ������� ���� */
	double betaAngle; /* ���� �������� �������� */

	std::string name; /* ��� �������� */
	std::string section; /* ��������� */

	unsigned short pin1; /* ������ � ������ ���� */
	unsigned short pin2; /* ������ �� ������ ���� */

	/* Default constructor*/
	Member(unsigned int id, std::string name, unsigned int node1, unsigned int node2,
		unsigned short pin1, unsigned short pin2, double betaAngle, std::string section);
};