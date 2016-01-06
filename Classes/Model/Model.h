#pragma once

class Model {
private:
	/* Collection of nodes */
	static std::vector<Node> nodes;

	/*Collection of members*/
	static std::vector<Member> members;

	/*Collection of restraints*/
	static std::vector<Restraint> restraints;

	/*Collection of load cases*/
	static std::vector<LoadCase> loadCases;

	/*Collection of loads*/
	static std::vector<Load> loads;

	/* Creates nodes */
	static void createNodes(ScadAPI& handle);

	// Creates members
	static void createMembers(ScadAPI& handle);

	// Creates restraint
	static void createRestraints(ScadAPI& handle);

	// Creates load cases
	static void createLoadCases(ScadAPI& handle);

	// Creates loads
	static void createLoads(ScadAPI& handle);

public:
	
	/* Add object to Model */
	static void addObject(Instance *object);

	/* Create Model */
	static void create(std::string fileName);
};

