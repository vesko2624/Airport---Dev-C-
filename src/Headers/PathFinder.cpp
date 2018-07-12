#include "../Classes/PathFinder.h"
PathFinder::PathFinder(){
	Active = false;
	Jumps = 0;
	Price = 0;
}
PathFinder::~PathFinder(){
	if(Active){
		if(Jumps > 0)
			delete current_route;
		else
			delete[] current_route;	
	}
}	
bool PathFinder::FindRoutes(Route,FlightData){

}	
