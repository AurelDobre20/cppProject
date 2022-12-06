#include<iostream>
#include<string>

using namespace std;



enum LAWN {
	NONE, Lawn_1, Lawn_2, Lawn_3
};

class Ticket {
private:
	const int id;
	bool VIP;
	LAWN lawn;
	int tribune;
	int* boxes;
	int noBoxes;
public:
	Ticket():id(0) {
		this->VIP = false;
		this->boxes = nullptr;
		this->noBoxes = 0;
		this->tribune = 0;
		this->lawn = LAWN::NONE;

	}

	Ticket(bool VIP, LAWN lawn, int tribune, int* boxes, int noBoxes):id(id) {
		this->VIP = VIP;
		if (boxes != nullptr && noBoxes > 0) {
			this->boxes = new int[noBoxes];
			for (int i = 0; i < noBoxes; i++) {
				this->boxes[i] = boxes[i];
			}
		}
		this->noBoxes = noBoxes;
		this->tribune = tribune;
		this->lawn = lawn;
	}




};
