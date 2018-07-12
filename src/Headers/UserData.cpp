#include "../Airport.h"
#include "../Classes/Recorder.h"
// Constructors
UserData::UserData(Counter& counter): counter_(counter){
	Recorder Rec;
	UserInfo temp;
	while(Rec.Read_User(temp)){
		this -> add_user(temp,1);
	}
}

// Methods
Counter& UserData::get_counter(){
	return counter_;
}
void UserData::display(){
//	if(!flights_.size()) cout << "There is nothing to display.\n"; // Add error codes
	cout << '\n';
	for(int i = 0; i < users_.size(); ++i){
		users_[i].display();
		cout << '\n';
	}
}
const int UserData::get_last_id(){
	int max = 0;
	for(int i = 0; i < users_.size(); ++i) if(users_[i].id_ > max) max = users_[i].id_;
	return max;
}

void UserData::add_user(){
	UserInfo user;
	user.read();
	this-> add_user(user);
}

void UserData::add_user(UserInfo& user, bool auto_adjust_id){
	bool interfere = false;
	int index = 0;
	for(int i = 0; i < users_.size(); ++i){
		if(users_[i].id_ == user.id_){
			interfere = true;
			index = i;
		}
	}
	if(auto_adjust_id){
		user.id_ = get_last_id() + 1;
		UserInfo::kLastUserId_ = user.id_ + 1;
		users_.push_back(user);
		counter_.add_user(user);
		return;
	}
	if(interfere){
		bool loop;
		cout << "There is already a user request with that id.";
		do{
			loop = false;
			int choice;
			cout << "\n\t1. Replace it.";
			cout << "\n\t2. Change the id of the current one.";
			cout << "\n\t3. I want to see it first.";
			cout << "\n\tEnter your decision: ";
			while(!validate_cin(choice, 1, 3)) cout << "\tEnter a valid decision: ";
			switch(choice){
				case 1:
					users_[index] = user;
					break;
				case 2:
					user.id_ = get_last_id() + 1;
					UserInfo::kLastUserId_ = user.id_ + 1;
					add_user(user);
					break;
				case 3:
					cout << '\n';
					user.display();
					loop = true;
					break;
			}
		}while(loop);
	}else{
		users_.push_back(user);
		counter_.add_user(user);
	}
}
bool UserData::get_user_by_id(UserInfo* user, const int& id){
	for(int i = 0; i < users_.size(); ++i)
		if(users_[i].id_ == id){
			user = &users_[i];
			return true;
		}
	return false;
}
vector<UserInfo> UserData::get_users_by_departure_city(string city){
	vector<UserInfo> users_from_city;
	for(int i = 0; i < users_.size(); ++i)
		if(users_[i].route_.get_departure() == city) users_from_city.push_back(users_[i]);
	return users_from_city;
}
vector<UserInfo> UserData::get_users_by_arrival_city(string city){
	vector<UserInfo> users_to_city;
	for(int i = 0; i < users_.size(); ++i)
		if(users_[i].route_.get_arrival() == city) users_to_city.push_back(users_[i]);
	return users_to_city;
}
vector<UserInfo>& UserData::get_users(){
	return users_;
}
int UserData::getsize(){
	return users_.size();
}
