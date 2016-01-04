#pragma once
// Standard
#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <iterator>
#include <vector>

// Project
#include "resource.h"
#include "stdafx.h"

// Boost
#include <boost/lexical_cast.hpp>

// SCAD
#include "API/Include/ScadAPIX.hxx"
#pragma comment(lib, "API/Lib/32/SCADAPIX.lib" )

// Classes
#include "Classes/Time/Timer.h"

#include "Classes/Instance/Instance.h"
#include "Classes/Instance/Node.h"

#include "Classes/Model/Model.h"

#include "Classes/FileChecker/FileFormatChecker.h"

#include "Classes/Reader/Reader.h"
#include "Classes/Reader/File/File_Version_1_Reader.h"
#include "Classes/Reader/Document/DocumentReader.h"
#include "Classes/Reader/Document/Node/Document_10_Version_1_Reader.h"
#include "Classes/Reader/ReaderFactory.h"