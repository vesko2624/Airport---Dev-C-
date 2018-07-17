#include "../Classes/Recorder.h"

Recorder::Recorder(){
	User_file = false;
	Flight_file = false;
	Input_File_Flights.open("../src/DataBase/Flight_Records.txt");
	Input_File_Users.open("../src/DataBase/User_Records.txt");
}
Recorder::~Recorder(){
	if(Flight_file)
		Flight_Output_File.close();
	if(User_file)
		User_Output_File.close();
	Input_File_Flights.close();
	Input_File_Users.close();
}

void Recorder::Record_Flight(FlightInfo& temp){
	Flight_Output_File <<temp.id_ << "  " << temp.route_.get_departure() << " " << temp.route_.get_arrival() << " " << temp.departure_time_.get_as_string() << " " << temp.arrival_time_.get_as_string() << " " << temp.price_ << '\n';
}
void Recorder::Record_User(UserInfo& temp){
	User_Output_File << temp.id_ << " " << temp.name_ << " " << temp.route_.get_departure() << " " << temp.route_.get_arrival() << " " << temp.departure_time_.get_as_string() << " " << temp.arrival_time_.get_as_string() << '\n';
}

bool Recorder::Read_Flight(FlightInfo& temp){
	int id,day_d,month_d,year_d,hour_d,minute_d,day_a,month_a,year_a,hour_a,minute_a;
	double price;
	string departure,arrival;
	if(!(Input_File_Flights >> id)) return false;
	 Input_File_Flights >> departure >> arrival >> day_d >> month_d >> year_d >> hour_d >> minute_d >> day_a >> month_a >> year_a >> hour_a >> minute_a >> price;
	temp.id_ = id;
	temp.price_ = price;
	temp.route_.set_route(departure,arrival);
	temp.departure_time_.set_date(day_d,month_d,year_d,hour_d,minute_d);
	temp.arrival_time_.set_date(day_a,month_a,year_a,hour_a,minute_a);
	return true;
}

bool Recorder::Read_User(UserInfo& temp){
	int id,day_d,month_d,year_d,hour_d,minute_d,day_a,month_a,year_a,hour_a,minute_a;
	string name,departure,arrival;
	if(!(Input_File_Users >> id >> name >> departure >> arrival >> day_d >> month_d >> year_d >> hour_d >> minute_d >> day_a >> month_a >> year_a >> hour_a >> minute_a)) return false;
	temp.id_ = id;
	temp.name_ = name;
	temp.route_.set_route(departure,arrival);
	temp.departure_time_.set_date(day_d,month_d,year_d,hour_d,minute_d);
	temp.arrival_time_.set_date(day_a,month_a,year_a,hour_a,minute_a);
}
void Recorder::Reload_Flight_Records_file(){
	Input_File_Flights.close();
	Input_File_Flights.open("../src/DataBase/Flight_Records.txt");
}

void Recorder::Close_flight_folder(){
	Flight_Output_File.close();
	Flight_file = false;
}
void Recorder::Close_user_folder(){
	User_Output_File.close();
	User_file = false;
}

void Recorder::Open_flight_folder(){
	Flight_Output_File.open("../src/DataBase/Flight_Records.txt");
	Flight_file = true;
}
void Recorder::Open_user_folder(){
	User_Output_File.open("../src/DataBase/User_Records.txt");
	User_file = true;
}

void Recorder::Record_FlightData(FlightData& flights){
	Open_flight_folder();
	for(int i = 0;i < flights.flights_.size(); ++i)
		Record_Flight(flights.flights_[i]);
	Close_flight_folder();
}

void Recorder::Record_UserData(UserData& users){
	Open_user_folder();
	for(int i = 0;i < users.users_.size(); ++i)
		Record_User(users.users_[i]);
	Close_user_folder();
}
