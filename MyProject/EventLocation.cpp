#include<iostream>
#include<string>
#include"Event.cpp"

using namespace std;


class EventLocation {
private:
	Event eventName;
	int maxNoSeats;
	int noRow;
	char* zones;
	string place;
public:

	EventLocation() {
		this->maxNoSeats = 0;
		this->noRow = 0;
		this->zones=nullptr;
		this->place = "";
	}

	EventLocation(int maxNoSeats, int noRow,const char* zones, string place, string date, string time, string name): eventName(date, time, name) {
		this->noRow = noRow;
		this->maxNoSeats = maxNoSeats;
		this->place = place;
		if (zones != nullptr) {
			this->zones = new char[strlen(zones) + 1];
			strcpy_s(this->zones, strlen(zones) + 1, zones);
		}
		else {
			this->zones = nullptr;
		}
	}




};

