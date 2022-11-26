#include<iostream>
#include<String>

using namespace std;

class Event {
private:
	string date;
	string time;
	string name;
public:
	Event() {
		date = "";
		time = "";
		name = "";
	}
	Event(string date, string time, string name) {
		this->date = date;
		this->time = time;
		this->name = name;
	}

	void setDate(string date) {
		if (date.length() > 0) {
			this->date = date;
		}
	}

	string getDate() {
		return this->date;
	}

	void setTime(string time) {
		if (time.length() > 0) {
			this->time = time;
		}
	}

	string getTime() {
		return this->time;
	}

	void setName(string name) {
		if (name.length() > 0) {
			this->name = name;
		}
	}

	string getName() {
		return this->name;
	}

};