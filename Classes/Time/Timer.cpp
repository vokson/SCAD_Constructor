#include "Header.h"
#pragma once

/* Write current date & time to std::clog */
std::string Timer::get() {

	//Write Date&Tiem to Log
	time_t t = std::time(0);   // get time now
	
	struct tm * now = localtime(&t);
	return boost::lexical_cast<std::string>(now->tm_year + 1900) + '-'
		+ boost::lexical_cast<std::string>(now->tm_mon + 1) + '-'
		+ boost::lexical_cast<std::string>(now->tm_mday) + " "
		+ boost::lexical_cast<std::string>(now->tm_hour) + ":"
		+ boost::lexical_cast<std::string>(now->tm_min) + ":"
		+ boost::lexical_cast<std::string>(now->tm_sec) + "   ";
}
