#include "stdafx.h"
#include "Model.h"
Model::Model() {
this->nodes.push_back(Node(1,"Node 1",0,3,0));
this->nodes.push_back(Node(2,"",0,0,0));

this->members.push_back(Member(1, 1, 2, 32, 63, 90, "STZ RUSSIAN p_wide_h 18 TMP 1.2e-005", "1st element"));

};