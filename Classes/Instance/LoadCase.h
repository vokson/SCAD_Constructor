#pragma once
#include <string>
#include <vector>

class LoadCase {
public:
	int id; /* ����� ���� */
	std::string name; /* ��� ���� */
	std::string type; /* ��������� ���������� */
	std::vector <double> masses; /* ������ ������������� ��� ������� ���� */
	int massCount;

	/* Default constructor*/
	LoadCase(int id, std::string name, std::string type) {
		this->id = id;
		this->name = name;
		this->type = type;
		this->massCount = 0;
	}

	/* Mass Matrix Constructor*/
	LoadCase(int id, std::string name, std::string type, std::vector <double> masses) {
		this->id = id;
		this->name = name;
		this->type = type;
		this->masses = masses;
		this->massCount = masses.size()-1;
	}
};