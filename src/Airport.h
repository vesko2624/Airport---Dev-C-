#include <iostream>
#include <sstream>
#include <limits>
using std::cout;
using std::cin;
using std::stringstream;
using std::numeric_limits;
using std::streamsize;
#define TABS "		"

#ifndef AIRPORT_H
#define AIRPORT_H

void Clear_cin();

template<class T, class S> // Convert variable of type T to variable of type S
T get(S variable){         // For example get<string>(5) returns "5";
	T temp;
	stringstream stream;
	stream << variable;
	stream >> temp;
	return temp;
}


template<class T>
bool validate_cin(T& choice, T min = -3211233, T max = -3211233){
	bool to_return = true, has_min = min != -3211233, has_max = has_min && max != -3211233;
	if(!(cin >> choice)) to_return = false;
	if(has_min)
		if(choice < min) to_return = false;
	if(has_max)
		if(choice > max) to_return = false;
	if(!to_return) cout<<" Bad input! \n "; 
	Clear_cin();
	return to_return;
}

#endif
