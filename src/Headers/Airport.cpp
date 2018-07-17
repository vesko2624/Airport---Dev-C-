#include "../Airport.h"

void clear_cin(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n' );	
	cin.sync();
}
