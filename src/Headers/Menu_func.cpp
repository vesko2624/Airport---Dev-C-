#include "../Airport.h"

#include "../Classes/Menu_func.h"
using std::cout; using std::cin;


void make_choice(FlightData& flights, UserData& users){
	int choice = 0 ;
	cout << " 1. New flight record.      RABOTI\n" ;
	cout << " 2. New user request.       RABOTI\n";
	cout << " 3. Change flight by id     RABOTI\n";
	cout << " 4. Get all flights         RABOTI\n";
	cout << " 5. All user requests       RABOTI\n";
	cout << " 6. Find flight by request  NEED ALGORITHM\n";
	cout << " 7. Find flights from a city after a certain hour \n";
	cout << " 8. Find city with most flights   RABOTI \n";
	cout << " 9. Find city with most users     RABOTI\n";
	cout << " 10. Record in file               RABOTI\n";
	cout << " 11. Exit \n";
	if(!validate_cin(choice,1,11)) return;
	
	switch (choice){
		case 1 :  Make_flight_record(flights); break;
		case 2:   Make_user_record(users); break;
		case 3:   Change_flight_id(flights); break;
		case 4:   Display_all_flights(flights); break;
		case 5:   Display_all_users(users); break;
//		case 6:   Find_flight_by_request(); break;
//		case 7:   Find_flights_city_hour(); break;
		case 8:   Find_city_with_most_flights(flights); break;
		case 9:   Find_city_with_most_users(users); break;
		case 10:   Record_in_file(flights, users); break; 
		case 11:  exit(0);
	}
}

void Make_flight_record(FlightData& flights){
	FlightInfo flight;
	if(flight.read()) flights.add_flight(flight,1);
}
void Make_user_record(UserData& users){
	UserInfo user;
	if(user.read()) users.add_user(user,1);
}
void Change_flight_id(FlightData& flights){
	FlightInfo* flight;
	int id;
	cout << "Enter id: ";
	cin >> id;
	if(flights.get_flight_by_id(flight,id)) flight->read();
}
void Display_all_flights(FlightData& flights){
	flights.display();
	system("pause");
}
void Display_all_users(UserData& users){
	users.display();
	system("pause");
}
void Find_city_with_most_flights(FlightData& flights){
	string city;
	int count;
	if(flights.get_counter().count_flight_departure(city, count)){
		cout << "Most frequent departure city is " << city <<". There are " << count << " flights.\n";
	}
}
void Find_city_with_most_users(UserData& users){
	string city;
	int count;
	if(users.get_counter().count_flight_frequent_requests(city, count)){
		cout << "Most frequent fly requests are from " << city << ". There are " << count << " flight requests in " << city << '\n';
	}
}
void Record_in_file(FlightData& flights,UserData& users){
	Recorder Rec;
	Rec.Record_FlightData(flights);
	Rec.Record_UserData(users);
}
