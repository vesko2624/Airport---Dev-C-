#include <iostream>
#include <string>
#include "../Airport.h"
#include "FlightData.h"
using std::string;
using std::cout;
using std::cin;

#ifndef _PathFinder_
#define _PathFinder_

class PathFinder{
	public:
		bool FindRoutes(Route,FlightData);
		void Add_Jump(Route){
		}
		void Remove_jump(){
		}
		PathFinder();
		~PathFinder();		

		void Display_Route();
	private:
		bool Active;
		Route *current_route;
		int Jumps;
		double Price;
};

#endif
