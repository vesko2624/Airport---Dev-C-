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
//		FlightInfo(const string& departure, const string& arrival,const string& departure_time, const string& arrival_time, const double& price);
		
		bool read();
		void display();
		Route get_route();
	private:
		static long long kLastFlightId_;
		int id_;
		Route route_;
		Date departure_time_, arrival_time_;
		double price_;
		
		friend class Recorder;
		friend class FlightData;
};

#endif
