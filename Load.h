#pragma once
#include <vector>

class Load {
public:
	int loadCase; /* ����� ���������� */
	int loadType; /* ��� �������� */
	int loadDirection; /* ����������� �������� */
	int number; /* ����� ���� ��� ��������, � ������� ��������� ��������*/
	std::vector <double> data; /* ������ �������� �������� */
	int dataCount; /* ���-�� ��������� � data */

	/* Default constructor*/
	Load(int loadCase, int number, int loadType, int loadDirection, std::vector <double> data) {
		this->loadCase = loadCase;
		this->number = number;
		this->loadType = loadType;
		this->loadDirection = loadDirection;
		
		this->data = data;
		this->dataCount = data.size();
	}
};