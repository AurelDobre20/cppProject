#include<iostream>
#include<string>

using namespace std;


class EventLocation {
private:
	int maxNoSeats;
	int noRow;
	char* zones;
	string codeSeat;
public:
	EventLocation() {
		this->maxNoSeats = 0;
		this->noRow = 0;
		this->zones=nullptr;
		this->codeSeat = "";
	}
};

int main() {

}