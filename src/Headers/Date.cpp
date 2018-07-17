#include "../Airport.h"
#include "../Classes/Date.h"

// Constructors
Date::Date(){
	day_ = 31;
	month_ = 12;
	year_ = 2100;
	hour_ = 23;
	minute_ = 59;
}
Date::Date(const int& day, const int& month, const int& year, const int& hour, const int& minute): day_(day), month_(month), year_(year), hour_(hour), minute_(minute){
}


// Methods
void Date::display() const{
	cout << day_ << ". " << month_ << ". " << year_ << " year - " 
		<< hour_ << " : " << minute_ << '\n';
}
bool Date::read(){
	int day, month, year, hour, minute;
	cout << '\n';
	cout << "\tEnter day: ";
	if(!validate_cin(day, 1, 31)) return false;
	cout << "\tEnter month: ";
	if(!validate_cin(month, 1, 12)) return false;
	cout << "\tEnter year: ";
	if(!validate_cin(year, 1900, 2100)) return false;
	cout << "\tEnter hour: ";
	if(!validate_cin(hour, 0, 23)) return false;
	cout << "\tEnter minute: ";
	if(!validate_cin(minute, 0, 59)) return false;
	set_date(day, month, year, hour, minute);
	return true;
}


// Getters and/or Setters
void Date::set_date(const int& day, const int& month, const int& year, const int& hour, const int& minute){
	day_ = day;
	month_ = month;
	year_ = year;
	hour_ = hour;
	minute_ = minute;
}

string Date::get_as_string(){
	string date_string;

	string day_as_string = get<string>(day_);
	string month_as_string = get<string>(month_);
	string year_as_string = get<string>(year_);
	string hour_as_string = get<string>(hour_);
	string minute_as_string = get<string>(minute_);

	date_string = day_as_string + " " 
		+ month_as_string + " "
		+ year_as_string + " " 
		+ hour_as_string + " " 
		+ minute_as_string;	

	return date_string;
}


// Opearators overloading
bool operator<(const Date& date1, const Date& date2){
	if(date1.year_ < date2.year_) return true;
	if(date1.month_ < date2.month_) return true;
	if(date1.day_ < date2.day_) return true;
	if(date1.hour_ < date2.hour_) return true;
	if(date1.minute_ < date2.minute_) return true;
	return false;
}
