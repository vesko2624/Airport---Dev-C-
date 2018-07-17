#include <iostream>
#include "PathFinder.h"
#include "Recorder.h"

#ifndef _Menufunc_
#define _Menufunc_

void flights_menu(FlightData&);
void users_menu(UserData&);
void main_menu(FlightData&, UserData&);

void make_flight_record(FlightData&);
void make_user_record(UserData&);
void change_flight_id(FlightData& flights);
void display_all_flights(FlightData& flights);
void display_all_users(UserData& users);
void seek_for_route(FlightData& flights);
void find_flights_city_hour(FlightData& flights);
void find_city_with_most_flights(FlightData& flights);
void find_city_with_most_users(UserData& users); 
void record_in_file(FlightData& flights,UserData& users); 

#endif
