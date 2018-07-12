#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

#ifndef _Route_
#define _Route_

class Route{
	public:
		void read_departure();
		void read_arrival();
		
		void display_departure() const;
		void display_arrival() const;
		
		void set_departure(const string& departure);
		void set_arrival(const string& arrival);
		void set_route(const string& departure,const string& arrival);
		
		string get_departure() const;
		string get_arrival() const;
	private:
		string departure_, arrival_;
};

#endif
