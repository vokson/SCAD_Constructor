#include "Header.h"

// Static variables' definition
std::vector<Node> Model::nodes;

void Model::addObject(Instance *object) {

	//Node
	if (Node* derivedObject = dynamic_cast<Node*>(object)) {
		Model::nodes.push_back(*derivedObject);
	}
}

/* Create Model */
void Model::create(std::string fileName) {

	std::clog << std::endl << Timer::get() << "   CREATE MODEL" << std::endl;

	ScadAPI	handle(NULL);
	const static UnitsAPI Un[3] = { { "m", 1 },{ "cm", 100 },{ "T", 1 } };

	if (ApiCreate(&handle) != APICode_OK) ApiMsg("Error");  //  создание объекта API и контроль
	if (ApiClear(handle) != APICode_OK) ApiMsg("Error");    //  после открытия можно не делать
	if (ApiSetLanguage(handle, 1) != APICode_OK) ApiMsg("Error");
	ApiSetName(handle, fileName.c_str());
	ApiSetUnits(handle, Un);
	if (ApiSetTypeSchema(handle, 5) != APICode_OK) ApiMsg("Error");

	Model::createNodes(handle);

	std::clog << "   Write file '" << fileName << "'" << std::endl;

	APICode Code;
	Code = ApiWriteProject(handle, (fileName + ".spr").c_str());
	if (Code != APICode_OK) { APIPhrase(handle, Code); }
	ApiRelease(&handle);
}

/* Creates nodes */
void Model::createNodes(ScadAPI& handle) {
	// узлы
	ApiNodeAddSize(handle, Model::nodes.size());
	for (u_int i = 0; i < Model::nodes.size(); i++) {
		ApiNodeUpdate(handle, Model::nodes[i].id, Model::nodes[i].x, Model::nodes[i].y, Model::nodes[i].z);
		ApiNodeSetName(handle, Model::nodes[i].id, Model::nodes[i].name.c_str());
	}
}