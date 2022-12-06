#include<iostream>
#include"Ticket.cpp"
#include"EventLocation.cpp"

using namespace std;

int main() {
	cout << "Hello world" << endl;

	Event event1("11/05/2023", "22:10", "Campionat");
	Event event2 = event1;
	event2.setName("Seara film");
	event2.setTime("17:30");
	cout << event1;
	cout << event2;

	if (event1 > event2) {
		cout << endl << "Event1 has a longer name." << endl;
	}
	if (event1 < event2) {
		cout << endl << "Event1 has a shorter name." << endl;
	}
	event1.displayTheEventDetails();





	EventLocation eL(22, 2, "Zona vestica", "Bucuresti", "11/12/2022", "12:12", "Circ");

	EventLocation eL1 = eL;
	cout << endl << "seats per row: " << eL1.calculateNoOfSeatsPerRow();
	eL1.setNoRow(4);
	eL1.setMaxNoSeats(40);
	cout << endl << "seats per row: " << eL1.calculateNoOfSeatsPerRow();

	cout << eL1;

	EventLocation eL2;
	eL2 = eL1;
	cout << eL2;

	eL2 = eL2 + 2;

	cout << eL2;

	eL2 = eL2 - 2;

	cout << eL2;


	int boxes[4] = { 12,21,34,42 };
	Ticket t1(1, true, Lawn_1, 4, boxes, 4);
	Ticket t2 = t1;
	cout << t2;
	Ticket t3;
	t3 = t2;
	cout << t3;


	if (!t3) {
		cout << endl << "not a vip ticket";
	}
	else {
		cout << endl << "it is a vip ticket";
	}

	if (t3==t2) {
		cout << endl << "same lawn";
	}
	else {
		cout << endl << "not the same lawn";
	}
}