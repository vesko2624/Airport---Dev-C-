#include "../Classes/Route.h"

// Methods
void Route::read_departure(){
	cin >> departure_;
}
void Route::read_arrival(){
	cin >> arrival_;
}

void Route::display_departure() const{
	cout << this-> departure_ << '\n';
}
void Route::display_arrival() const{
	cout << this-> arrival_ << '\n';
}


// Getters and setters
void Route::set_departure(const string& departure){
	this-> departure_ = departure;
}
void Route::set_arrival(const string& arrival){
	this-> arrival_ = arrival;
}

string Route::get_departure() const{
	return this-> departure_;
}
string Route::get_arrival() const{
	return this-> arrival_;
}

void Route::set_route(const string& departure,const string& arrival){
	this -> departure_ = departure;
	this -> arrival_ = arrival;
}

