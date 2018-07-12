#include "src/Airport.h"
#include "src/Classes/Menu_func.h"
//stanislav.dimov@quanterall.com
bool running = true;

int main(){
	Counter counter;
	FlightData flights(counter);
	UserData users(counter);
    while(running){
        make_choice(flights, users);
    }
    return 0;
}
