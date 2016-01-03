#pragma once
// Standard
#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <iterator>
#include <vector>

// Boost
#include <boost/lexical_cast.hpp>

//// SCAD
//#include "API/Include/ScadAPIX.hxx"

// Classes
#include "Classes/FileChecker/FileFormatChecker.h"

#include "Classes/Document/DocumentReader.h"
#include "Classes/Document/File/File_Version_1_Reader.h"
#include "Classes/Document/Node/Document_10_Version_1_Reader.h"
#include "Classes/Document/DocumentReaderFactory.h"


#pragma comment(lib, "API/Lib/32/SCADAPIX.lib" )
