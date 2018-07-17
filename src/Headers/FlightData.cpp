#include "../Airport.h"
#include "../Classes/Recorder.h" 
// Constructors
FlightData::FlightData(Counter& counter): counter_(counter){
}

// Methods
void FlightData::load_flights(){
	Recorder Rec;
	FlightInfo temp;
	while(Rec.Read_Flight(temp)){
		this -> add_flight(temp,1);
	}
}

void FlightData::display(){
	cout << '\n';
	for(int i = 0; i < flights_.size(); ++i){
		flights_[i].display();
		cout << '\n';
	}
}

Counter& FlightData::get_counter(){
	return counter_;
}

const int FlightData::get_last_id(){
	int max = 0;
	for(int i = 0; i < flights_.size(); ++i) if(flights_[i].id_ > max) max = flights_[i].id_;
	return max;
}

void FlightData::add_flight(){
	FlightInfo flight;
	flight.read();
	this-> add_flight(flight);
}

void FlightData::add_flight(FlightInfo& flight, bool auto_adjust_id){
	bool interfere = false;
	int index = 0;
	for(int i = 0; i < flights_.size(); ++i){
		if(flights_[i].id_ == flight.id_){
			interfere = true;
			index = i;
		}
	}
	if(auto_adjust_id){
		flight.id_ = get_last_id() + 1;
		FlightInfo::kLastFlightId_ = flight.id_ + 1;
		flights_.push_back(flight);
		counter_.add_flight(flight);
		return;
	}
	if(interfere){
		bool loop;
		cout << "There is already a flight with that id.";
		do{
			loop = false;
			int choice;
			cout << "\n\t1. Replace it.";
			cout << "\n\t2. Change the id of the current one.";
			cout << "\n\t3. I want to see it first.";
			cout << "\n\tEnter your decision: ";
			while(!validate_cin(choice, 1, 3)) cout << "\tEnter a valid decision: ";
			switch(choice){
				case 1:
					flights_[index] = flight;
					break;
				case 2:
					flight.id_ = get_last_id() + 1;
					FlightInfo::kLastFlightId_ = flight.id_ + 1;
					add_flight(flight);
					break;
				case 3:
					cout << '\n';
					flight.display();
					loop = true;
					break;
			}
		}while(loop);
	}else{
		flights_.push_back(flight);
		counter_.add_flight(flight);
	}
}

bool FlightData::get_flight_by_id(FlightInfo& flight, const int& id){
	for(int i = 0; i < flights_.size(); ++i)
		if(flights_[i].id_ == id){
			flight = *(&flights_[i]);
			return true;
		}
	return false;
}

bool FlightData::change_flight_by_id(const int& id){
	for(int i = 0; i < flights_.size(); ++i)
		if(flights_[i].id_ == id){
			return flights_[i].read();
		}
	return false;
}

vector<FlightInfo> FlightData::get_flights_by_departure_city(string city){
	vector<FlightInfo> flights_from_city;
	for(int i = 0; i < flights_.size(); ++i)
		if(flights_[i].route_.get_departure() == city) flights_from_city.push_back(flights_[i]);
	return flights_from_city;
}

vector<FlightInfo> FlightData::get_flights_by_arrival_city(string city){
	vector<FlightInfo> flights_to_city;
	for(int i = 0; i < flights_.size(); ++i)
		if(flights_[i].route_.get_arrival() == city) flights_to_city.push_back(flights_[i]);
	return flights_to_city;
}

vector<FlightInfo>& FlightData::get_flights(){
	return flights_;
}

int FlightData::get_size(){
	return flights_.size();
}
