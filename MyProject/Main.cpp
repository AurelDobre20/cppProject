#include<iostream>
#include"Event.cpp"

using namespace std;

int main() {
	cout << "Hello world" << endl;

	Event e("11/22/2022", "22:10", "Loca");

	cout << e.getDate() << endl;
	cout << e.getTime() << endl;
	cout << e.getName() << endl;
}