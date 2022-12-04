#include<iostream>
#include"EventLocation.cpp"

using namespace std;

int main() {
	cout << "Hello world" << endl;

	Event e("11/22/2022", "22:10", "Loca");


	/*cout << e;
	cin >> e;
	cout << e;*/
	e.displayTheEventDetails();


	EventLocation eL(21, 2, "asa", "asa", "11/12/2022", "alal", "asda");


}