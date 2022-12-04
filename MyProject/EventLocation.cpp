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
		cout<<endl<< "Event date: " << this->eventName.getDate();
		cout << endl << "Event name: "<<this->eventName.getName();
		cout << endl << "Event time: " << this->eventName.getTime()<<endl;
	}

	void setEventName(string date, string time, string name) {
		this->eventName.setDate(date);
		this->eventName.setTime(time);
		this->eventName.setName(name);
	}

	int getMaxNoSeats() {
		return this->maxNoSeats;
	}

	void setMaxNoSeats(int noSeats) {
		if (noSeats > 0) {
			this->maxNoSeats = noSeats;
		}
	}

	int getNoRow() {
		return this->maxNoSeats;
	}

	void setNoRow(int noRow) {
		if (noRow>0) {
			this->noRow = noRow;
		}
	}

	string getPlace() {
		return this->place;
	}

	void setPlace(string place) {
		if (place.length() > 0) {
			this->place = place;
		}
	}

	char* getZones() {
		if (this->zones != nullptr) {
			char* copy = new char[strlen(this->zones) + 1];
			strcpy_s(copy, strlen(this->zones) + 1, this->zones);
			return copy;
		}
		return nullptr;
	}

	void setZones(const char* zones) {
		if (zones != nullptr) {
			this->zones = new char[strlen(zones) + 1];
			strcpy_s(this->zones, strlen(zones) + 1, zones);
		}
	}

	friend ostream& operator<< (ostream& out, EventLocation eL) {

		out << "------------------" << endl;

		out << "Event name: ";
		out << eL.eventName.getName() << endl;


		out << "Event time: ";
		out << eL.eventName.getTime() << endl;


		out << "Event date: ";
		out << eL.eventName.getDate() << endl;
		

		out << "No. of seats: ";
		out << eL.maxNoSeats << endl;

		out << "No. of rows: ";
		out << eL.noRow << endl;

		out << "Place: ";
		out << eL.place << endl;

		out << "Zone: ";

		if (eL.zones != nullptr) {
			out << eL.zones<<endl;
		}

		out << "------------------" << endl;

		return out;

	}

	friend istream& operator>> (istream& in, EventLocation& eL)
	{
		cout << "Event name: ";
		string buffer;
		in >> buffer;
		eL.eventName.setName(buffer);

		cout << "Event time: ";
		in >> buffer;
		eL.eventName.setTime(buffer);

		cout << "Event date: ";
		in >> buffer;
		eL.eventName.setDate(buffer);

		cout << "Event place: ";
		in >> buffer;
		eL.setPlace(buffer);

		cout << "No. of seats: ";
		in >> eL.maxNoSeats;

		cout << "No. of rows: ";
		in >> eL.noRow;
		
		cout << "Zone: ";
		in >> buffer;
		eL.setZones(buffer.c_str());


		return in;
	}

	void operator=(const EventLocation& eL) {

		
		if (this == &eL) {
			
			return;
		}
		this->eventName = eL.eventName;
		this->place = eL.place;
		this->noRow = eL.noRow;
		this->maxNoSeats = eL.maxNoSeats;

		if (this->zones) {
			delete[] this->zones;
			this->zones = nullptr;
		}

		if (eL.zones != nullptr) {

			this->zones = new char[strlen(eL.zones) + 1];
			memcpy(this->zones,
				eL.zones,
				strlen(eL.zones) + 1);
		}
		else {
			this->zones = nullptr;
		}

	}

	EventLocation operator+(int no)
	{
		EventLocation result = *this;
		result.noRow += no;
		return result;
	}

	EventLocation operator-(int no)
	{
		EventLocation result = *this;
		result.noRow -= no;
		return result;
	}


};

