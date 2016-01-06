#pragma once

class LoadCase : public Instance {
protected:
	/* Abstract fucntion to make class polymorphous */
	void abstractFunction();


public:
	unsigned short id; /* Номер загружения */
	std::string name; /* Имя загружения */
	std::string type; /* Параметры загружения */
	std::vector <double> masses; /* Массив коэффициентов для матрицы масс */

	/* Mass Matrix Constructor*/
	LoadCase(unsigned short id, std::string name, std::string type, std::vector <double> masses);
};