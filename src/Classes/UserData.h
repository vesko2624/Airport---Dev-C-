#include <iostream>
#include <vector>
#include "Counter.h"
#include "UserInfo.h"
using std::vector;
using std::cout;
using std::cin;

#ifndef USERDATA_H
#define USERDATA_H

class UserData{
	public:
		UserData(Counter& counter);
		Counter& get_counter();
		void display();
		
		void add_user();
		void add_user(UserInfo& flight, bool auto_adjust_id = 0);
		const int get_last_id();
		bool get_user_by_id(UserInfo* user, const int& id);
		vector<UserInfo> get_users_by_departure_city(string city);
		vector<UserInfo> get_users_by_arrival_city(string city);
		vector<UserInfo>& get_users();
		int getsize();
	private:
		vector<UserInfo> users_;
		Counter counter_;

		friend class Recorder;
};

#endif
