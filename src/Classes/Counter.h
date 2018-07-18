#include <vector>
#include <unordered_map>
#include "UserInfo.h"
#include "FlightInfo.h"
using std::unordered_map;
using std::pair;

#ifndef COUNTER_H
#define COUNTER_H

struct container{
	container(): count(0){}
	container(string city): city(city), count(1){}
	int count;
	string city;
};
class Counter{
	public:
		Counter();
		void add_flight(FlightInfo&);
		void add_user(UserInfo& user);
		unordered_map<string, int> get_list() const;
		bool count_flight_departure(string& city, int& num_flight);
		bool count_flight_frequent_requests(string& city, int& num_requests);
	private:
		unordered_map<string, int> cities_;
		unordered_map<string, int> requests_;
		
		unordered_map<string, int> total_cities_;
};
#endif
