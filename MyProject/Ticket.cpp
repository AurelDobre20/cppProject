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

	~Ticket() {
		delete[] boxes;
		boxes = nullptr;
	}

	int getId() {
		return this->id;
	}

	void setBoxes(int* boxes, int noBoxes) {
		if (boxes != nullptr && noBoxes > 0) {
			this->boxes = new int[noBoxes];
			for (int i = 0; i < noBoxes; i++) {
				this->boxes[i] = boxes[i];
			}
		}
		this->noBoxes = noBoxes;
	}

	int* getBoxes() {
		if (this->boxes != nullptr && this->noBoxes > 0) {

			int* copy = new int[noBoxes];
			for (int i = 0; i < this->noBoxes; i++) {
				copy[i] = this->boxes[i];
			}
			return copy;
		}
	}

	void setVIP(bool value) {
		this->VIP = value;
	}
	bool getVIP() {
		return this->VIP;
	}

	void setLawn(int value) {
		if (value > 0 && value < 4) {
			this->lawn = (LAWN)value;
		}
	}
	string getLawn() {
		if (this->lawn == 1) {
			return "Lawn 1" ;
		}
		if (this->lawn == 2) {
			return "Lawn 2";
		}
		if (this->lawn == 3) {
			return "Lawn 3";
		}
	}






};
