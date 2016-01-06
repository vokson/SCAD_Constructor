#pragma once

class Load : public Instance {
protected:
	/* Abstract fucntion to make class polymorphous */
	void abstractFunction();

public:
	unsigned short loadCase; /* ����� ���������� */
	unsigned short loadType; /* ��� �������� */
	unsigned short loadDirection; /* ����������� �������� */
	unsigned int number; /* ����� ���� ��� ��������, � ������� ��������� ��������*/
	std::vector <double> data; /* ������ �������� �������� */

	/* Default constructor*/
	Load(unsigned short loadCase, unsigned int number, unsigned short loadType, unsigned short loadDirection, std::vector <double> data);
};