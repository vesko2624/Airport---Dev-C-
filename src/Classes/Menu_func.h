#include <iostream>
#include "FlightData.h"
#include "UserData.h"
#include "Recorder.h"

#ifndef _Menufunc_
#define _Menufunc_

void make_choice(FlightData&, UserData&);
void Make_flight_record(FlightData&);
void Make_user_record(UserData&);
void Change_flight_id(FlightData& flights);
void Display_all_flights(FlightData& flights);
void Display_all_users(UserData& users);
void Find_flight_by_request();
void Find_flights_city_hour();
void Find_city_with_most_flights(FlightData& flights);
void Find_city_with_most_users(UserData& users); 
void Record_in_file(FlightData& flights,UserData& users); 

#endif
