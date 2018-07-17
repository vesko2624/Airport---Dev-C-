#include "../Airport.h"
#include "../Classes/UserInfo.h"

/* Static variables */
long long UserInfo::kLastUserId_ = 0;


// Constructors
UserInfo::UserInfo(): id_(++UserInfo::kLastUserId_){
	
}


// Methods
bool UserInfo::read(){
	bool valid = true;
	cout << "User name:"<< TABS;
	cin >> name_;
	cout << "Flying from:"<< TABS ;
	route_.read_departure();
	
	cout << "Flying to:"<< TABS ;
	route_.read_arrival();
	
	cout << "Earliest departure time:"<< TABS ;
	if(!departure_time_.read()) valid = false;
	
	cout << "Arrives not later than:"<< TABS;
	if(!arrival_time_.read()) valid = false;;
	
	if(!valid) cout << "You've entered invalid information, it cannot be saved\n"; // ADD ERROR CODES;
	return valid;
}

void UserInfo::display(){
	cout << "Request id:\t\t" << TABS << id_ << '\n';  
	cout << "User name:\t\t\t\t" << name_ << '\n';
	
	cout << "Requested departure city:\t\t";
	route_.display_departure();
	
	cout << "Requested arrival city:\t\t\t";
	route_.display_arrival();
	
	cout << "Requested earliest departure time:\t";
	departure_time_.display();
	
	cout << "Arrives not later than:\t" << TABS;
	arrival_time_.display();
}

Route UserInfo::get_user_request(){
	Route route;
	route.set_departure(route_.get_departure());
	route.set_arrival(route_.get_arrival());
	return route;
}
