#include "stdafx.h"
#include "Model.h"
Model::Model() {
// +++ NODES +++
this->nodes.push_back(Node(1, "", 0, 3, 0));
this->nodes.push_back(Node(2, "", 0, 3, 5));
this->nodes.push_back(Node(3, "", 0, 0, 0));
this->nodes.push_back(Node(4, "", 0, 0, 5));
this->nodes.push_back(Node(5, "", 5, 0, 0));
this->nodes.push_back(Node(6, "", 5, 0, 5));
this->nodes.push_back(Node(7, "", 0, 0, 0.5));
this->nodes.push_back(Node(8, "", 4.5, 0, 5));
this->nodes.push_back(Node(9, "", 0, 0, 1));
this->nodes.push_back(Node(10, "", 0, 2.5, 5));
// +++ MEMBERS +++
this->members.push_back(Member(1, "C1", 1, 2, 0, 0, 0, "STZ RUSSIAN p_col_k 1 TMP 1.2e-005"));
this->members.push_back(Member(2, "C2", 3, 7, 0, 0, 0, "STZ RUSSIAN p_col_k 1 TMP 1.2e-005"));
this->members.push_back(Member(3, "C3", 5, 6, 0, 0, 90, "STZ RUSSIAN p_wide_h 5 TMP 1.2e-005"));
this->members.push_back(Member(4, "B1", 4, 8, 0, 0, 0, "STZ RUSSIAN p_norm_b 14 TMP 1.2e-005"));
this->members.push_back(Member(5, "B2", 2, 4, 0, 0, 0, "STZ RUSSIAN p_norm_b 14 TMP 1.2e-005"));
this->members.push_back(Member(6, "Brace 1", 7, 8, 0, 0, 0, "STZ RUSSIAN diam 390 TMP 1.2e-005"));
this->members.push_back(Member(7, "Brace 2", 9, 10, 0, 0, 0, "STZ RUSSIAN diam 390 TMP 1.2e-005"));
this->members.push_back(Member(8, "C2", 7, 9, 0, 0, 0, "STZ RUSSIAN p_col_k 1 TMP 1.2e-005"));
this->members.push_back(Member(9, "C2", 9, 4, 0, 0, 0, "STZ RUSSIAN p_col_k 1 TMP 1.2e-005"));
this->members.push_back(Member(10, "B1", 8, 6, 0, 0, 0, "STZ RUSSIAN p_norm_b 14 TMP 1.2e-005"));
// +++ RESTRAINTS +++
this->restraints.push_back(Restraint(1, 0));
this->restraints.push_back(Restraint(3, 0));
this->restraints.push_back(Restraint(5, 0));
// +++ LOAD CASES +++
std::vector <double> massMatrixVector;
this->loadCases.push_back(LoadCase(1, "DL", "Type=0  Mode=1  LongTime=1  ReliabilityFactor=1.05" ));
this->loadCases.push_back(LoadCase(2, "LL", "Type=0  Mode=1  LongTime=1  ReliabilityFactor=1.05" ));
massMatrixVector.clear();
massMatrixVector.push_back(0);
massMatrixVector.push_back(1.2);
massMatrixVector.push_back(1.5);
this->loadCases.push_back(LoadCase(3,"Wind", "Type=2  ReliabilityFactor=1.1  21 5 1  1 3 0 0 0 5 18 1 0 0.3 1", massMatrixVector));
};