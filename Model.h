#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Node.h"
#include "Member.h"
#include "Restraint.h"
#include "LoadCase.h"
#include "API/Include/ScadAPIX.hxx"


class Model {
public:
	/*Collection of nodes*/
	std::vector<Node> nodes;

	/*Collection of members*/
	std::vector<Member> members;

	/*Collection of restraints*/
	std::vector<Restraint> restraints;

	/*Collection of load cases*/
	std::vector<LoadCase> loadCases;

	// Default constructor
	Model();

	// Creates nodes
	void createNodes(ScadAPI& handle) {
		// узлы
		ApiNodeAddSize(handle, this->nodes.size());
		for (u_int i = 0; i < this->nodes.size(); i++) {
			ApiNodeUpdate(handle, this->nodes[i].id, this->nodes[i].x, this->nodes[i].y, this->nodes[i].z);
			ApiNodeSetName(handle, this->nodes[i].id, this->nodes[i].name.c_str());
		}
	}

	// Creates restraint
	void createRestraints(ScadAPI&	handle) {
		
		// связи	
		u_int nodeArray[1];

		for (u_int i = 0; i < this->restraints.size(); i++) {

			nodeArray[0] = this->restraints[i].id;
			ApiSetBound(handle,this->restraints[i].fix, 1, nodeArray, TRUE);
		}
	}

	// Creates load cases
	void createLoadCases(ScadAPI& handle) {

		for (u_int i = 0; i < this->loadCases.size(); i++) {
            std::cout << "I = " << i << std::endl;

			// TYPE
			ApiSetLoadDescription(handle, this->loadCases[i].id, this->loadCases[i].type.c_str());
			// NAME
			ApiSetLoadName(handle, this->loadCases[i].id, this->loadCases[i].name.c_str());

			// MASSES
			int massArraySize = this->loadCases[i].masses.size();
			
			if ( massArraySize > 0) {
				std::cout << "massArraySize = " << massArraySize << std::endl;
				ApiSetLoadMass(handle, this->loadCases[i].id, massArraySize, &this->loadCases[i].masses[0]);
			}
		}
	}

	// Creates members
	void createMembers(ScadAPI& handle) {
		// Add count of members
		ApiElemAdd(handle, this->members.size());

		// Update members
		u_int nodeArray[2];
		u_int elementArray[1];
		double angleArray[1];

		for (u_int i = 0; i < this->members.size(); i++) {
			nodeArray[0] = this->members[i].node1;
			nodeArray[1] = this->members[i].node2;
			ApiElemUpdate(handle, this->members[i].id, 5, 2, nodeArray);

			// Name
			ApiElemSetName(handle, this->members[i].id, this->members[i].name.c_str());

			// Section
			u_int section = ApiSetRigid(handle, this->members[i].section.c_str());
			elementArray[0] = this->members[i].id;
			ApiSetRigidElem(handle, section, 2, elementArray);

			// Pins
			if (this->members[i].pin1 > 0) {
				ApiSetJoint(handle, this->members[i].pin1, this->members[i].id, 1, 0);
			}
			if (this->members[i].pin2 > 0) {
				ApiSetJoint(handle, this->members[i].pin2, this->members[i].id, 2, 0);
			}

			// Angle
			angleArray[0] = members[i].betaAngle;
			ApiSetSystemCoordElem(handle, ApiGroupRod, ApiRodCornerInDegrees, 1, angleArray, 1, elementArray);
		}

		
	}
	
};

