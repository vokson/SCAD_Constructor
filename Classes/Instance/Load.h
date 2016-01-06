#pragma once

class Load : public Instance {
protected:
	/* Abstract fucntion to make class polymorphous */
	void abstractFunction();

public:
	unsigned short loadCase; /* Номер загружения */
	unsigned short loadType; /* Тип нагрузки */
	unsigned short loadDirection; /* Направление нагрузки */
	unsigned int number; /* Номер узла или элемента, к которым приложена нагрузка*/
	std::vector <double> data; /* Массив значений нагрузок */

	/* Default constructor*/
	Load(unsigned short loadCase, unsigned int number, unsigned short loadType, unsigned short loadDirection, std::vector <double> data);
};