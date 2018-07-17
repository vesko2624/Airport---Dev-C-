#include <iostream>
using std::cout;
using std::cin;
using std::string;
#ifndef _Date_
#define _Date_

class Date{
	public:
		Date();
		Date(const int& day, const int& month, const int& year, const int& hour, const int& minute);
		
		bool read();
		void display() const;
		
		void set_date(const int& day, const int& month, const int& year, const int& hour, const int& minute);
		string get_as_string();
		
		friend bool operator<(const Date&, const Date&);
	private:
		int day_, month_, year_, hour_, minute_;
};

#endif
