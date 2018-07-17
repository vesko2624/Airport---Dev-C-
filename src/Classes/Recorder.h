#include <fstream>
#include "FlightData.h"
#include "UserData.h"
using std::ifstream; using std::ofstream;

#ifndef _Recorder_
#define _Recorder_
class Recorder{
	private:
		ofstream Flight_Output_File;
		ofstream User_Output_File;
		ifstream Input_File_Flights;
		ifstream Input_File_Users;
		bool User_file,Flight_file;
	public:
		void Record_FlightData(FlightData&);
		void Record_UserData(UserData&);
		void Open_flight_folder();
		void Open_user_folder();
		void Close_flight_folder();
		void Close_user_folder();
		void Record_Flight(FlightInfo&);
		void Record_User(UserInfo&);
		bool Read_Flight(FlightInfo&);
		bool Read_User(UserInfo& temp);
		void Reload_Flight_Records_file();
		void Reload_User_Recors_file();
		Recorder();
		~Recorder();
};
#endif

