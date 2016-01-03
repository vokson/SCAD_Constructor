#pragma once

class Model {
protected:
	/* Collection of nodes */
	static std::vector<Node> nodes;

	///*Collection of members*/
	//std::vector<Member> members;

	///*Collection of restraints*/
	//std::vector<Restraint> restraints;

	///*Collection of load cases*/
	//std::vector<LoadCase> loadCases;

	///*Collection of loads*/
	//std::vector<Load> loads;

public:
	
	/* Add object to Model */
	static void addObject(Instance *object);

	

	//// Creates nodes
	//void createNodes(ScadAPI& handle) {
	//	// узлы
	//	ApiNodeAddSize(handle, this->nodes.size());
	//	for (u_int i = 0; i < this->nodes.size(); i++) {
	//		ApiNodeUpdate(handle, this->nodes[i].id, this->nodes[i].x, this->nodes[i].y, this->nodes[i].z);
	//		ApiNodeSetName(handle, this->nodes[i].id, this->nodes[i].name.c_str());
	//	}
	//}

	//// Creates restraint
	//void createRestraints(ScadAPI&	handle) {
	//	
	//	// связи	
	//	u_int nodeArray[1];

	//	for (u_int i = 0; i < this->restraints.size(); i++) {

	//		nodeArray[0] = this->restraints[i].id;
	//		ApiSetBound(handle,this->restraints[i].fix, 1, nodeArray, TRUE);
	//	}
	//}

	//// Creates load cases
	//void createLoadCases(ScadAPI& handle) {

	//	for (u_int i = 0; i < this->loadCases.size(); i++) {
	//		// TYPE
	//		ApiSetLoadDescription(handle, this->loadCases[i].id, this->loadCases[i].type.c_str());
	//		// NAME
	//		ApiSetLoadName(handle, this->loadCases[i].id, this->loadCases[i].name.c_str());

	//		if ( this->loadCases[i].massCount > 0) {
	//			ApiSetLoadMass(handle, this->loadCases[i].id, this->loadCases[i].massCount, &this->loadCases[i].masses[0]);
	//		}
	//	}
	//}

	//// Creates loads
	//void createLoads(ScadAPI& handle) {

	//	// Create element's array
	//	u_int elementArray[1];

	//	for (u_int i = 0; i < this->loads.size(); i++) {
	//		// Only one element in array
	//		elementArray[0] = this->loads[i].number;

	//		ApiAppendForce(handle, this->loads[i].loadCase, this->loads[i].loadType, this->loads[i].loadDirection,
	//			this->loads[i].dataCount, &this->loads[i].data[0], 1, elementArray);
	//	}
	//}

	//// Creates members
	//void createMembers(ScadAPI& handle) {
	//	// Add count of members
	//	ApiElemAdd(handle, this->members.size());

	//	// Update members
	//	u_int nodeArray[2];
	//	u_int elementArray[1];
	//	double angleArray[1];

	//	for (u_int i = 0; i < this->members.size(); i++) {
	//		nodeArray[0] = this->members[i].node1;
	//		nodeArray[1] = this->members[i].node2;
	//		ApiElemUpdate(handle, this->members[i].id, 5, 2, nodeArray);

	//		// Name
	//		ApiElemSetName(handle, this->members[i].id, this->members[i].name.c_str());

	//		// Section
	//		u_int section = ApiSetRigid(handle, this->members[i].section.c_str());
	//		elementArray[0] = this->members[i].id;
	//		ApiSetRigidElem(handle, section, 2, elementArray);

	//		// Pins
	//		if (this->members[i].pin1 > 0) {
	//			ApiSetJoint(handle, this->members[i].pin1, this->members[i].id, 1, 0);
	//		}
	//		if (this->members[i].pin2 > 0) {
	//			ApiSetJoint(handle, this->members[i].pin2, this->members[i].id, 2, 0);
	//		}

	//		// Angle
	//		angleArray[0] = members[i].betaAngle;
	//		ApiSetSystemCoordElem(handle, ApiGroupRod, ApiRodCornerInDegrees, 1, angleArray, 1, elementArray);
	//	}

	//	
	//}
	
};

