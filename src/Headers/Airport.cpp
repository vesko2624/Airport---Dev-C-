#include "../Airport.h"

void Clear_cin(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n' );	
	cin.sync();
}

