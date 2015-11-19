#pragma once
#include <string>
#include <vector>

class LoadCase {
public:
	int id; /* Номер узла */
	std::string name; /* Имя узла */
	std::string type; /* Параметры загружения */
	std::vector <double> masses; /* Массив коэффициентов для матрицы масс */

	/* Default constructor*/
	LoadCase(int id, std::string name, std::string type) {
		this->id = id;
		this->name = name;
		this->type = type;
	}

	/* Mass Matrix Constructor*/
	LoadCase(int id, std::string name, std::string type, std::vector <double> masses) {
		this->id = id;
		this->name = name;
		this->type = type;
		this->masses = masses;
	}
};