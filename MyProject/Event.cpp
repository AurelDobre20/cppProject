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

	friend ostream& operator<< (ostream& out, Event e) {

		out << "------------------" << endl;

		out << "Event name: ";

		out << e.name<<endl;


		out << "Event time: ";

		out << e.time << endl ;


		out << "Event date: ";

		out << e.date << endl ;

		out << "------------------" << endl;

		return out;

	}

	friend istream& operator>> (istream& in, Event& e)
	{
		cout << "Event name: ";
		string buffer;
		in >> buffer;
		e.setName(buffer);

		cout << "Event time: ";
		string buffer1;
		in >> buffer1;
		e.setTime(buffer1);

		cout << "Event date: ";
		string buffer2;
		in >> buffer2;
		e.setDate(buffer2);

		return in;
	}

	void displayTheEventDetails() {
		cout << "The event name is " + this->name + " it will take place on " + this->date + " at the time " + this->time << endl;
		
	}

	bool operator>(Event e) {
		if (this->name.length() > e.name.length()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator<(Event e) {
		if (this->name.length() < e.name.length()) {
			return true;
		}
		else {
			return false;
		}
	}

};

