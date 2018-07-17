#include <iostream>
#include <string>
#include "Route.h"
#include "Date.h"
using std::string;
using std::cin;
using std::cout;

#ifndef _FlightInfo_
#define _FlightInfo_

class FlightInfo{
	public:
		FlightInfo();
		
		bool read();
		void display() const;
		
		Route get_route() const;
		Date get_departure_time() const;
		Date get_arrival_time() const;
		double get_price() const;
	private:
		static long long kLastFlightId_;
		int id_;
		Route route_;
		Date departure_time_, arrival_time_;
		double price_;
		
		friend class Recorder;
		friend class FlightData;
		friend class PathFinder;
};

#endif
