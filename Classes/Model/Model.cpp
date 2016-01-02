// Change
#include "stdafx.h"
#include "Model.h"
Model::Model() {
// +++ NODES +++
this->nodes.push_back(Node(1, "", 0, 0, 0));
this->nodes.push_back(Node(2, "", 0, 0, 0.5));
this->nodes.push_back(Node(3, "", 0, 0, 1));
this->nodes.push_back(Node(4, "", 0, 0, 5));
this->nodes.push_back(Node(5, "", 0, 0.5, 5));
this->nodes.push_back(Node(6, "", 0, 2.5, 5));
this->nodes.push_back(Node(7, "", 0, 3, 0));
this->nodes.push_back(Node(8, "", 0, 3, 5));
this->nodes.push_back(Node(9, "", 1, 0, 5));
this->nodes.push_back(Node(10, "", 2.7, 0, 5));
this->nodes.push_back(Node(11, "", 4.5, 0, 5));
this->nodes.push_back(Node(12, "", 5, 0, 0));
this->nodes.push_back(Node(13, "", 5, 0, 1));
this->nodes.push_back(Node(14, "", 5, 0, 5));
this->nodes.push_back(Node(15, "", 5, 0, 8));
this->nodes.push_back(Node(16, "", 5, 0, 10));
// +++ MEMBERS +++
this->members.push_back(Member(1, "C1", 7, 8, 0, 0, 0, "STZ RUSSIAN p_col_k 1 TMP 1.2e-005"));
this->members.push_back(Member(2, "C2", 1, 2, 0, 0, 0, "STZ RUSSIAN p_col_k 1 TMP 1.2e-005"));
this->members.push_back(Member(3, "C3", 12, 14, 0, 0, 90, "STZ RUSSIAN p_wide_h 5 TMP 1.2e-005"));
this->members.push_back(Member(4, "C4", 14, 16, 0, 0, 90, "STZ RUSSIAN p_wide_h 5 TMP 1.2e-005"));
this->members.push_back(Member(5, "Балка 1", 4, 11, 0, 0, 0, "STZ RUSSIAN p_norm_b 14 TMP 1.2e-005"));
this->members.push_back(Member(6, "B2", 4, 6, 0, 0, 0, "STZ RUSSIAN p_norm_b 14 TMP 1.2e-005"));
this->members.push_back(Member(7, "Brace 1", 2, 11, 56, 48, 0, "STZ RUSSIAN diam 390 TMP 1.2e-005"));
this->members.push_back(Member(8, "Brace 2", 3, 6, 56, 48, 0, "STZ RUSSIAN diam 390 TMP 1.2e-005"));
this->members.push_back(Member(9, "C2", 2, 3, 0, 0, 0, "STZ RUSSIAN p_col_k 1 TMP 1.2e-005"));
this->members.push_back(Member(10, "C2", 3, 4, 0, 0, 0, "STZ RUSSIAN p_col_k 1 TMP 1.2e-005"));
this->members.push_back(Member(11, "B2", 6, 8, 0, 32, 0, "STZ RUSSIAN p_norm_b 14 TMP 1.2e-005"));
this->members.push_back(Member(12, "Балка 1", 11, 14, 0, 16, 0, "STZ RUSSIAN p_norm_b 14 TMP 1.2e-005"));
// +++ RESTRAINTS +++
this->restraints.push_back(Restraint(7, 63));
this->restraints.push_back(Restraint(1, 7));
this->restraints.push_back(Restraint(12, 63));
// +++ LOAD CASES +++
std::vector <double> massMatrixVector;
this->loadCases.push_back(LoadCase(1, "DL", "Type=0  Mode=1  LongTime=1  ReliabilityFactor=1.05" ));
this->loadCases.push_back(LoadCase(2, "LL", "Type=0  Mode=1  LongTime=1  ReliabilityFactor=1.05" ));
massMatrixVector.clear();
massMatrixVector.push_back(0);
massMatrixVector.push_back(1.2);
massMatrixVector.push_back(1.5);
this->loadCases.push_back(LoadCase(3,"Wind", "Type=2  ReliabilityFactor=1.1  21 5 1  1 3 0 0 0 5 18 1 0 0.3 1", massMatrixVector));
// +++ LOADS +++
std::vector <double> loadVector;
loadVector.clear();
// Distributed Member Load
loadVector.push_back(3);
loadVector.push_back(0.5);
loadVector.push_back(-5);
loadVector.push_back(2.5);
this->loads.push_back(Load(2, 6, 17, 3, loadVector));
loadVector.clear();
// Nodal Load
loadVector.push_back(6.6);
this->loads.push_back(Load(2, 8, 0, 5, loadVector));
loadVector.clear();
// Concentrated Member Load
loadVector.push_back(-3.6);
loadVector.push_back(1);
this->loads.push_back(Load(1, 5, 15, 3, loadVector));
loadVector.clear();
// Distributed Member Load
loadVector.push_back(2.3);
loadVector.push_back(1);
loadVector.push_back(2.8142857142857);
loadVector.push_back(5);
this->loads.push_back(Load(1, 3, 17, 2, loadVector));
loadVector.clear();
// Nodal Load
loadVector.push_back(14.3);
this->loads.push_back(Load(1, 14, 0, 1, loadVector));
loadVector.clear();
// Distributed Member Load
loadVector.push_back(2.8142857142857);
loadVector.push_back(0);
loadVector.push_back(3.2);
loadVector.push_back(3);
this->loads.push_back(Load(1, 4, 17, 2, loadVector));
loadVector.clear();
// Nodal Load
loadVector.push_back(3.4);
this->loads.push_back(Load(2, 6, 0, 2, loadVector));
loadVector.clear();
// Nodal Load
loadVector.push_back(2.1);
this->loads.push_back(Load(2, 6, 0, 4, loadVector));
loadVector.clear();
// Nodal Load
loadVector.push_back(10);
this->loads.push_back(Load(2, 6, 0, 5, loadVector));
loadVector.clear();
// Concentrated Member Load
loadVector.push_back(3.7);
loadVector.push_back(2.7);
this->loads.push_back(Load(1, 5, 15, 1, loadVector));
loadVector.clear();
// Concentrated Member Load
loadVector.push_back(2.6);
loadVector.push_back(2.7);
this->loads.push_back(Load(1, 5, 15, 3, loadVector));
loadVector.clear();
// Concentrated Member Load
loadVector.push_back(1.4);
loadVector.push_back(2.7);
this->loads.push_back(Load(1, 5, 15, 6, loadVector));
};