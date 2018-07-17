#include "../Airport.h"
#include "../Classes/Menu_func.h"
using std::cout; using std::cin;

void flights_menu(FlightData& flights){
	system("cls");
	int choice = 0;
	cout << "-------------------- Flights Menu --------------------\n";
	cout << " 1. New flight record \n";
	cout << " 2. Change flight by id \n";
	cout << " 3. Display all flights \n";
	cout << " 4. Seek for route \n";
	cout << " 5. Find flights from a city after a certain hour \n";
	cout << " 6. Find city with most flights \n";
	cout << " 7. Back to Main Menu \n";
	cout << "Make your choice: ";
	while(!validate_cin(choice, 1, 7)){
		cout << "Make a valid choice: ";
	}
	
	system("cls");
	switch(choice){
		case 1: make_flight_record(flights); break;
		case 2: change_flight_id(flights); break;
		case 3: display_all_flights(flights); break;
		case 4: seek_for_route(flights); break;
		case 5: find_flights_city_hour(flights); break;
		case 6: find_city_with_most_flights(flights); break;
		case 7: return;
	}
	if(choice != 7) system("pause");
	flights_menu(flights);
}

void users_menu(UserData& users){
	system("cls");
	int choice = 0;
	cout << "---------------------- Users Menu ----------------------\n";
	cout << " 1. New user request. \n";
	cout << " 2. Display all user requests \n";
	cout << " 3. Find city with most users \n";
	cout << " 4. Back to Main Menu \n";
	cout << "Make your choice: ";
	while(!validate_cin(choice, 1, 4)){
		cout << "Make a valid choice: ";
	}
	system("cls");
	switch(choice){
		case 1: make_user_record(users); break;
		case 2: display_all_users(users); break;
		case 3: find_city_with_most_users(users); break;
		case 4: return;
	}
	if(choice != 4) system("pause");
	users_menu(users);
}

void main_menu(FlightData& flights, UserData& users){
	system("cls");
	int choice = 0 ;
	cout << "---------------------- Main Menu ----------------------\n";
	cout << " 1. Flights Menu \n";
	cout << " 2. Users Menu \n";
	cout << " 3. Record in file \n";
	cout << " 4. Exit \n";
	cout << "Make your choice: ";
	while(!validate_cin(choice,1,4)){
		cout << "Make a valid choice: ";
	}
	if(choice != 4) system("cls");
	switch (choice){
		case 1:  flights_menu(flights); break;
		case 2:  users_menu(users); break;
		case 3:  record_in_file(flights, users); break; 
		case 4:  exit(0);
	}
}

void make_flight_record(FlightData& flights){
	FlightInfo flight;
	if(flight.read()) flights.add_flight(flight,1);
}

void make_user_record(UserData& users){
	UserInfo user;
	if(user.read()) users.add_user(user,1);
}

void change_flight_id(FlightData& flights){
	FlightInfo flight;
	int id;
	cout << "Enter id: ";
	cin >> id;
	flights.change_flight_by_id(id);
}

void display_all_flights(FlightData& flights){
	flights.display();
}

void display_all_users(UserData& users){
	users.display();
}

void seek_for_route(FlightData& flights){
	string departure, arrival;
	int choice = 0;
	PathFinder finder(flights);
	cout << "Flying from:"<< TABS ;
	cin >> departure;
	
	cout << "Flying to:"<< TABS ;
	cin >> arrival;
	
	cout << '\n';
	cout << "1. Best price. \n";
	cout << "2. Shortest route. \n";
	cout << "3. All possible routes\n";
	cout << "Make your choice: ";
	while(!validate_cin(choice, 1, 3)){
		cout << "Make a valid choice: ";
	}
	system("cls");
	switch(choice){
		case 1: finder.get_best_price(departure, arrival).display(); break;
		case 2: finder.get_best_flight(departure, arrival).display(); break;
		case 3: 
			vector<FlightData> all_routes = finder.get_all_flights(departure, arrival);
			for(int i = 0; i < all_routes.size(); ++i){
				cout << "\n------------------------- Route " << i + 1 << " -------------------------\n";
				all_routes[i].display();
			}
			cout << "\n---------------------------------------------------------\n";
			break;
	}
}

void find_flights_city_hour(FlightData& data){
	int flight_counter = 0;
	Date input_date;
	string departure;
	cout << "Enter city: ";
	cin >> departure;
	cout << "Enter date: ";
	if(!input_date.read()) return;
	vector<FlightInfo> flights = data.get_flights();
	for(int i = 0; i < flights.size(); ++i){
		if(flights[i].get_route().get_departure() == departure && flights[i].get_departure_time() < input_date){
			cout << "------------------------- Flight " << ++flight_counter << " -------------------------\n";
			flights[i].display();
		}
	}
	cout << "------------------------------------------------------------\n";
}

void find_city_with_most_flights(FlightData& flights){
	string city;
	int count;
	if(flights.get_counter().count_flight_departure(city, count)){
		cout << "Most frequent departure city is " << city <<". There are " << count << " flights.\n";
	}
}

void find_city_with_most_users(UserData& users){
	string city;
	int count;
	if(users.get_counter().count_flight_frequent_requests(city, count)){
		cout << "Most frequent fly requests are from " << city << ". There are " << count << " flight requests in " << city << '\n';
	}
}

void record_in_file(FlightData& flights,UserData& users){
	Recorder rec;
	rec.Record_FlightData(flights);
	rec.Record_UserData(users);
}
