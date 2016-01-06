#pragma once

class LoadCase : public Instance {
protected:
	/* Abstract fucntion to make class polymorphous */
	void abstractFunction();


public:
	unsigned short id; /* ����� ���������� */
	std::string name; /* ��� ���������� */
	std::string type; /* ��������� ���������� */
	std::vector <double> masses; /* ������ ������������� ��� ������� ���� */

	/* Mass Matrix Constructor*/
	LoadCase(unsigned short id, std::string name, std::string type, std::vector <double> masses);
};