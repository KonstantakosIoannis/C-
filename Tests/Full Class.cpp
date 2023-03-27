#include <iostream>

using namespace std; 

//class building 
class building
{
private:
	string street;
	int price;
	int tm;

public:
	building()
	{
		this->street = "  ";
		this->price = 0;
		this->tm = 0;
		cout << "New default building " << endl;

	}
	building(string street, int price, int tm)
	{
		this->street = street;
		this->price = price;
		this->tm = tm;
		cout << "New building at :  " << this->street << endl;
	}

	virtual ~building() { cout << this->street << "Deleted " << endl; }

	virtual void print() {}

};


//class home
class home :public building 
{
	private:
		string* family;
		int number;
		int familyNumber;
		int position;

	public :
		home() :building()
		{
			cout << "New default home" << endl;
			family = NULL;
			number = 0;
			position = 0;
			familyNumber = 0;
		}

		home(string street, int price, int tm, int number, int familyNumber) :building(street, price, tm)
		{
			this->number = number;
			this->familyNumber = familyNumber;
			family = new string[familyNumber];
			this->position = 0;
			cout << "New home" << endl;
		}

		home(const home & orig)
		{
			cout << "Copy con " << endl;

			this->number = orig.number;
			this->familyNumber = orig.familyNumber;
			this->position = 0;
			this->family = new string[orig.familyNumber];
			for (int i = 0; i < orig.familyNumber; i++)
			{
				this->family[i] = orig.family[i];
				this->position = this->position + 1;
			}
			//memcpy(this->family, orig.family, orig.familyNumber * sizeof(string));
		}


		home& operator=(const home& orig)
		{
			if (&orig == this) return *this;
			this->number = orig.number;
			this->familyNumber = orig.familyNumber;
			this->position = 0;
			if (this->family != NULL)delete[] this->family;
			this->family = new string[orig.familyNumber];
			//memcpy(family, orig.family, orig.familyNumber * sizeof(string));
			for (int i = 0; i < orig.familyNumber; i++)
			{
				this->family[i] = orig.family[i];
				this->position = this->position + 1;
			}
			return *this;
		}


		void operator<<(string name)
		{
			family[this->position] = name;
			this->position=this->position+1;
		}

		friend ostream& operator<<(ostream& os, home& h)
		{
			os << h.family[0] << endl;
			return os;
		}

		void print()
		{
			for (int i = 0; i < familyNumber; i++) cout << family[i] << endl;
		}




		~home()
		{
			if (family != NULL)
			{
				delete[]family;
				family = NULL;
			}
			cout << "Deleting home" << endl;
		}


};




int main()
{
	



	//building b1;
	//building b2("Patisiwn", 100, 150);//road - price -  m^2

	
	//building();
	//building("liosiwn", 100, 150);

	//home (); 

	home h0;
	home h1("Sepoliwn", 350, 90, 12, 3);//road  - price - m^2 - number  - number of residents)

	h1 << "John";  
	h1 << "Tim";
	h1 << "Loulou";


	cout << h1; 
	h1.print();



	
	home h2 = h1;
	cout << h2;
	h2.print();
	

	home h3;
	h3 = h2;
	cout << h3;
	h3.print();

	

	return 0;
}
