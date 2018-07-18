#include "../Classes/Counter.h"
//Constructors
Counter::Counter(){
	
}


// Methods
void Counter::add_flight(FlightInfo& flight){
	++cities_[flight.get_route().get_departure()];
	total_cities_.insert({flight.get_route().get_departure(), total_cities_.size() + 1});
	total_cities_.insert({flight.get_route().get_arrival(), total_cities_.size() + 1});
}

void Counter::add_user(UserInfo& user){
	++requests_[user.get_user_request().get_departure()];
}

unordered_map<string, int> Counter::get_list() const{
	return total_cities_;
}

bool Counter::count_flight_departure(string& city, int& num_flights){
	num_flights = 0;
	for(unordered_map<string, int>::iterator i = cities_.begin(); i != cities_.end(); ++i){
		if(i->second > num_flights){
			city = i->first;
			num_flights = i->second;
		}
	}
	return num_flights;
}

bool Counter::count_flight_frequent_requests(string& city, int& num_requests){
	num_requests = 0;
	for(unordered_map<string, int>::iterator i = requests_.begin(); i != requests_.end(); ++i){
		if(i->second > num_requests){
			city = i->first;
			num_requests = i->second;
		}
	}
	return num_requests;
}
