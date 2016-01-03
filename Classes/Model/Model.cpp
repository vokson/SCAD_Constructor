#include "Header.h"

// Static variables' definition
std::vector<Node> Model::nodes;

void Model::addObject(Instance *object) {

	//Node
	if (Node* derivedObject = dynamic_cast<Node*>(object)) {
		Model::nodes.push_back(*derivedObject);
	}
}