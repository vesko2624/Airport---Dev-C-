#include "../Classes/Counter.h"
Counter::Counter(){
	
}
void Counter::add_flight(FlightInfo& flight){
	for(int i = 0; i < cities_.size(); ++i){
		if(cities_[i].city == flight.get_route().get_departure()){
			++cities_[i].count;
			return;
		}
	}
	cities_.push_back(container(flight.get_route().get_departure()));
}
void Counter::add_user(UserInfo& user){
	for(int i = 0; i < requests_.size(); ++i){
		if(requests_[i].city == user.get_user_request().get_departure()){
			++requests_[i].count;
			return;
		}
	}
	requests_.push_back(container(user.get_user_request().get_departure()));
}
bool Counter::count_flight_departure(string& city, int& num_flights) const{
	num_flights = 0;
	for(int i = 0; i < cities_.size(); ++i){
		if(cities_[i].count > num_flights){
			city = cities_[i].city;
			num_flights = cities_[i].count;
		}
	}
	return cities_.size();
}
bool Counter::count_flight_frequent_requests(string& city, int& num_requests) const{
	num_requests = 0;
	for(int i = 0; i < requests_.size(); ++i){
		if(requests_[i].count > num_requests){
			city = requests_[i].city;
			num_requests = requests_[i].count;
		}
	}
	return requests_.size();
}

