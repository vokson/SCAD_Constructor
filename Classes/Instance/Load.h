#pragma once
#include <vector>

class Load {
public:
	int loadCase; /* Номер загружения */
	int loadType; /* Тип нагрузки */
	int loadDirection; /* Направление нагрузки */
	int number; /* Номер узла или элемента, к которым приложена нагрузка*/
	std::vector <double> data; /* Массив значений нагрузок */
	int dataCount; /* Кол-во элементов в data */

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