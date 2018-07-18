#include "Airport.h"
#include "Classes/Menu_func.h"
//stanislav.dimov@quanterall.com

int main(){
	Counter counter;
	FlightData flights(counter);
	UserData users(counter);
	flights.load_flights();
    while(1){
        main_menu(flights, users);
    }
    return 0;
}
