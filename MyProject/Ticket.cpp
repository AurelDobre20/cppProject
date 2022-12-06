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
	static const float TICKER_PRICE;

	Ticket():id(0) {
		this->VIP = false;
		this->boxes = nullptr;
		this->noBoxes = 0;
		this->tribune = 0;
		this->lawn = LAWN::NONE;

	}

	Ticket(int id, bool VIP, LAWN lawn, int tribune, int* boxes, int noBoxes):id(id) {
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

	Ticket(const Ticket& t):id(t.id) {
		this->VIP = t.VIP;
		if (t.boxes != nullptr && t.noBoxes > 0) {
			this->boxes = new int[t.noBoxes];
			for (int i = 0; i < t.noBoxes; i++) {
				this->boxes[i] = t.boxes[i];
			}
		}
		this->noBoxes = t.noBoxes;
		this->tribune = t.tribune;
		this->lawn = t.lawn;
	}

	Ticket operator=(Ticket& t) {
		if (this == &t) {
			return;
		}
		if (this->boxes != nullptr) {
			delete[] boxes;
		}
		this->VIP = t.VIP;
		if (t.boxes != nullptr && t.noBoxes > 0) {
			this->boxes = new int[t.noBoxes];
			for (int i = 0; i < t.noBoxes; i++) {
				this->boxes[i] = t.boxes[i];
			}
		}
		this->noBoxes = t.noBoxes;
		this->tribune = t.tribune;
		this->lawn = t.lawn;
		return *this;
	
	}

	~Ticket() {
		delete[] boxes;
		boxes = nullptr;
	}

	static float getPrice() {
		return Ticket::TICKER_PRICE;
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

	friend ostream& operator<< (ostream& out, Ticket t) {

		out << "------------------" << endl;

		out << "Ticket id: ";
		out << t.id << endl;


		out << "Ticket lawn: ";
		if (t.lawn == 1) {
			out <<"Lawn 1"<<endl;
		}
		if (t.lawn == 2) {
			out << "Lawn 2"<<endl;
		}
		if (t.lawn == 3) {
			out << "Lawn 3"<<endl;
		}


		if (t.boxes != nullptr && t.noBoxes > 0) {
			out << endl << "No. of boxes: " << t.noBoxes << endl;
			for (int i = 0; i < t.noBoxes; i++) {
				out << "Box no: " <<i+1<<" has "<< t.boxes[i] <<" seats." << " ";
			}
			
		}


		out <<endl<< "Ticket tribune: ";
		out << t.tribune << endl;
		out << "------------------" << endl;

		

		return out;

	}

	friend istream& operator>> (istream& in, Ticket& t)
	{
		


		
		int no = 0;



		cout <<endl<< "Ticket lawn: ";
		in >> no;

		if (t.lawn == 1) {
			
			in >>no ;
			t.setLawn(no);
		}
		if (t.lawn == 2) {
			in >> no;
			t.setLawn(no);
		}
		if (t.lawn == 3) {
			in >> no;
			t.setLawn(no);
		}

		cout << endl << "No. of boxes: ";
		in >> no;
		


		if (no >0) {
			t.boxes = new int[no];
			for (int i = 0; i < no; i++) {
				cout << "Box no " << i + 1 << ": ";
				in >> t.boxes[i];
			}

		}


		cout << endl << "Ticket tribune: ";
		in >> t.tribune;
		


		return in;
	}


	bool operator!() {
		if (this->VIP) {
			return true;
		}
		else {
			return false;
		}
	}
	
	bool operator==(Ticket t) {
		if (this->lawn == t.lawn) {
			return true;
		}
		else {
			return false;
		}
	}







};


