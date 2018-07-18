#include "../Classes/PathFinder.h"
// Constructors
PathFinder::PathFinder(FlightData& flights): data_(flights), flights_(flights.get_flights()){
}


// Methods
int get_city(unordered_map<string, int>& cities, const string& city){
	int index = cities[city];
	return index? index : -1;
}

vector<complexRoute> getRoute(vector<a_flight>* connections, const int& size, const int& start, const int& end){
	vector<complexRoute> complex_routes;
	if(start > size || end > size - 1 || !get_to_city(complex_routes, {{0, end, Date(), Date(), 0}}, connections, size, start, end)) return {};
	return complex_routes;
}

bool get_to_city(vector<complexRoute>& complex_routes, vector<a_flight> calculations, vector<a_flight>* connections, const int& size, const int& start, const int& end){
	if(calculations.back().city == start){
		complexRoute solution(calculations);
		reverse(solution.passed_cities.begin(), solution.passed_cities.end());
		complex_routes.push_back(solution);
		return true;
	}
	bool has_other_cities = false;
	for(int i = 0; i < connections[calculations.back().city].size(); ++i){
		bool loop = false;
		for(int j = 0; j < calculations.size(); ++j){
			if(connections[calculations.back().city][i].city == calculations[j].city){
				loop = true;
				break;
			}
		}
		if(loop) continue;
		else{
			has_other_cities = true;
			
			// Check the date
			if(connections[calculations.back().city][i].arrival_time < calculations.back().departure_time){
				vector<a_flight> temp = calculations;
				temp.push_back(connections[calculations.back().city][i]);
				if(!get_to_city(complex_routes, temp, connections, size, start ,end)) continue;
			}else continue;
		}
	}
	if(!has_other_cities) return complex_routes.size();
	return true;
}

FlightData PathFinder::get_best_flight(const string& departure, const string& arrival){
	Counter temp_counter;
	FlightData flight_route(temp_counter);
	vector<a_flight> connections_[flights_.size() + 2];
	unordered_map<string, int> cities = data_.get_counter().get_list();
	for(int i = 0; i < flights_.size(); ++i){
		connections_[get_city(cities, flights_[i].route_.get_arrival())].push_back(a_flight(flights_[i].id_, get_city(cities, flights_[i].route_.get_departure()), flights_[i].departure_time_, flights_[i].arrival_time_, flights_[i].price_));
	}
	pair<int, int> minFlights;
	vector<complexRoute> temp = getRoute(connections_, cities.size() + 2, get_city(cities, departure), get_city(cities, arrival));
	if(temp.size() > 0){
		minFlights.first = temp[0].tracker;
		minFlights.second = 0;
	} else return flight_route;
	for(int i = 1; i < temp.size(); ++i){
		if(temp[i].tracker <= minFlights.first){
			if(temp[i].tracker == minFlights.first){
				if(temp[i].price < temp[minFlights.second].price){
					minFlights.first = temp[i].tracker;
					minFlights.second = i;
				}else continue;
			}
			minFlights.first = temp[i].tracker;
			minFlights.second = i;
		}
	}
	for(int i = 0; i < temp[minFlights.second].passed_cities.size() - 1; ++i){
		FlightInfo temp_flight;
		data_.get_flight_by_id(temp_flight, temp[minFlights.second].passed_cities[i].id);
		flight_route.add_flight(temp_flight);
	}
	return flight_route;
}

FlightData PathFinder::get_best_price(const string& departure, const string& arrival){
	Counter temp_counter;
	FlightData flight_route(temp_counter);
	vector<a_flight> connections_[flights_.size() + 2];
	unordered_map<string, int> cities = data_.get_counter().get_list();
	for(int i = 0; i < flights_.size(); ++i){
		connections_[get_city(cities, flights_[i].route_.get_arrival())].push_back(a_flight(flights_[i].id_, get_city(cities, flights_[i].route_.get_departure()), flights_[i].departure_time_, flights_[i].arrival_time_, flights_[i].price_));
	}
	pair<int, int> minPrice;
	vector<complexRoute> temp = getRoute(connections_, cities.size() + 2, get_city(cities, departure), get_city(cities, arrival));
	if(temp.size() > 0){
		minPrice.first = temp[0].price;
		minPrice.second = 0;
	} else return flight_route;
	for(int i = 1; i < temp.size(); ++i){
		if(temp[i].price <= minPrice.first){
			if(temp[i].price == minPrice.first){
				if(temp[i].tracker < temp[minPrice.second].tracker){
					minPrice.first = temp[i].price;
					minPrice.second = i;
				}else continue;
			}
			minPrice.first = temp[i].price;
			minPrice.second = i;
		}
	}
	for(int i = 0; i < temp[minPrice.second].passed_cities.size() - 1; ++i){
		FlightInfo temp_flight;
		data_.get_flight_by_id(temp_flight, temp[minPrice.second].passed_cities[i].id);
		flight_route.add_flight(temp_flight);
	}
	return flight_route;
}

vector<FlightData> PathFinder::get_all_flights(const string& departure, const string& arrival){
	Counter temp_counter;
	vector<FlightData> flight_routes;
	vector<a_flight> connections_[flights_.size() + 2];
	unordered_map<string, int> cities = data_.get_counter().get_list();
	for(int i = 0; i < flights_.size(); ++i){
		connections_[get_city(cities, flights_[i].route_.get_arrival())].push_back(a_flight(flights_[i].id_, get_city(cities, flights_[i].route_.get_departure()), flights_[i].departure_time_, flights_[i].arrival_time_, flights_[i].price_));
	}
	vector<complexRoute> temp = getRoute(connections_, cities.size() + 2, get_city(cities, departure), get_city(cities, arrival));
	for(int i = 0; i < temp.size(); ++i){
		FlightData route(temp_counter);
		for(int j = 0; j < temp[i].passed_cities.size() - 1; ++j){
			FlightInfo temp_flight;
			data_.get_flight_by_id(temp_flight, temp[i].passed_cities[j].id);
			route.add_flight(temp_flight);
		}
		flight_routes.push_back(route);
	}
	return flight_routes;
}

