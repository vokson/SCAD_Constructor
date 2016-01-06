#include "Header.h"

// Static variables' definition
std::vector<Node> Model::nodes;
std::vector<Member> Model::members;
std::vector<Restraint> Model::restraints;
std::vector<LoadCase> Model::loadCases;
std::vector<Load> Model::loads;

void Model::addObject(Instance *object) {

	//Node
	if (Node* derivedObject = dynamic_cast<Node*>(object)) {
		Model::nodes.push_back(*derivedObject);
	}

	//Member
	if (Member* derivedObject = dynamic_cast<Member*>(object)) {
		Model::members.push_back(*derivedObject);
	}

	//Restraint
	if (Restraint* derivedObject = dynamic_cast<Restraint*>(object)) {
		Model::restraints.push_back(*derivedObject);
	}

	//Load
	if (Load* derivedObject = dynamic_cast<Load*>(object)) {
		Model::loads.push_back(*derivedObject);
	}

	//LoadCase
	if (LoadCase* derivedObject = dynamic_cast<LoadCase*>(object)) {
		Model::loadCases.push_back(*derivedObject);
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
	Model::createMembers(handle);
	Model::createRestraints(handle);
	Model::createLoadCases(handle);
	Model::createLoads(handle);

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

// Creates members
void Model::createMembers(ScadAPI& handle) {
	// Add count of members
	ApiElemAdd(handle, Model::members.size());

	// Update members
	u_int nodeArray[2];
	u_int elementArray[1];
	double angleArray[1];

	for (u_int i = 0; i < Model::members.size(); i++) {
		nodeArray[0] = Model::members[i].node1;
		nodeArray[1] = Model::members[i].node2;
		ApiElemUpdate(handle, Model::members[i].id, 5, 2, nodeArray);

		// Name
		ApiElemSetName(handle, Model::members[i].id, Model::members[i].name.c_str());

		// Section
		u_int section = ApiSetRigid(handle, Model::members[i].section.c_str());
		elementArray[0] = Model::members[i].id;
		ApiSetRigidElem(handle, section, 2, elementArray);

		// Pins
		if (Model::members[i].pin1 > 0) {
			ApiSetJoint(handle, Model::members[i].pin1, Model::members[i].id, 1, 0);
		}
		if (Model::members[i].pin2 > 0) {
			ApiSetJoint(handle, Model::members[i].pin2, Model::members[i].id, 2, 0);
		}

		// Angle
		angleArray[0] = members[i].betaAngle;
		ApiSetSystemCoordElem(handle, ApiGroupRod, ApiRodCornerInDegrees, 1, angleArray, 1, elementArray);
	}
}

// Creates restraint
void Model::createRestraints(ScadAPI& handle) {

		// связи	
		u_int nodeArray[1];

		for (u_int i = 0; i < Model::restraints.size(); i++) {

			nodeArray[0] = Model::restraints[i].id;
			ApiSetBound(handle, Model::restraints[i].fix, 1, nodeArray, TRUE);
		}
	}

// Creates load cases
void Model::createLoadCases(ScadAPI& handle) {

		for (u_int i = 0; i < Model::loadCases.size(); i++) {
			// TYPE
			ApiSetLoadDescription(handle, Model::loadCases[i].id, Model::loadCases[i].type.c_str());
			// NAME
			ApiSetLoadName(handle, Model::loadCases[i].id, Model::loadCases[i].name.c_str());

			if (Model::loadCases[i].masses.size() > 0) {
				// Here count of members in masses array must be send as masses.size()-1. I don't know why.
				ApiSetLoadMass(handle, Model::loadCases[i].id, Model::loadCases[i].masses.size()-1, &Model::loadCases[i].masses[0]);
			}
		}
	}

// Creates loads
void Model::createLoads(ScadAPI& handle) {

		// Create element's array
		u_int elementArray[1];

		for (u_int i = 0; i < Model::loads.size(); i++) {
			// Only one element in array
			elementArray[0] = Model::loads[i].number;

			ApiAppendForce(handle, Model::loads[i].loadCase, Model::loads[i].loadType, Model::loads[i].loadDirection,
				Model::loads[i].data.size(), &Model::loads[i].data[0], 1, elementArray);
		}
	}
