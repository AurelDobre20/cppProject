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

	~EventLocation() {
		delete[] zones;
		zones = nullptr;
	}

	EventLocation(const EventLocation& eL){
		this->noRow = eL.noRow;
		this->maxNoSeats = eL.maxNoSeats;
		this->place = eL.place;
		if (eL.zones != nullptr) {
			this->zones = new char[strlen(eL.zones) + 1];
			strcpy_s(this->zones, strlen(eL.zones) + 1, eL.zones);
		}

	}

	void getEventName() {
		cout<<endl<<this->eventName.getDate();
		cout << endl << this->eventName.getName();
		cout << endl << this->eventName.getTime();
	}

	void setEventName(string date, string time, string name) {
		this->eventName.setDate(date);
		this->eventName.setTime(time);
		this->eventName.setName(name);
	}


};

