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

		home(const home & orig)// original source proto src
		{
			cout << "Copy con " << endl;

			this->number = orig.number;
			this->familyNumber = orig.familyNumber;
			this->position = 0;// sizitisimo
			this->family = new string[orig.familyNumber];
			for (int i = 0; i < orig.familyNumber; i++)
			{
				this->family[i] = orig.family[i];
				this->position = this->position + 1;
			}
			//memcpy(this->family, orig.family, orig.familyNumber * sizeof(string));//sizitisimo
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
	// H klasi home klironomei Dimosia thn klasi building

	//To ti pedia tha baleis se kathe klasi , to katalabaineis apo ta sxolia dipla
	//apo tin dimiourgia kathe antikeimenou sti main

	//kathe home krataei enan  pinaka me ta onomata autwn pou menoun se auto

	//h home klironomei tin methodo print apo to building
	//kai ektipwnei ola ta onomata pou exei mesa o pinakas pou anaferame pio panw



	//building b1;
	//building b2("Patisiwn", 100, 150);//dromos - timh spitiou - Tetragonika metra

	// poia i diafora autou me to panw?
	//building();
	//building("liosiwn", 100, 150);

	//home ();  omoiws , poia i diafora me ta parakatw?

	home h0;
	home h1("Sepoliwn", 350, 90, 12, 3);//dromos - timh spitiou - Tetragonika metra - arithmos oikias - posa atoma katoikoun se auto(px edw mia 4melis oikogenia)

	h1 << "John";  // gemisma tou pinaka pou krataei h home
	h1 << "Tim";
	h1 << "Loulou";


	cout << h1; // ektiposi tou protou keliou tou pinaka
	h1.print();



	
	home h2 = h1;
	cout << h2;
	h2.print();
	

	home h3;
	h3 = h2;
	cout << h3;
	h3.print();

	// na grapseis tin idia main , me dinamiki desmeysi mnimis kai na eksighsete 
	// ta ofelh ths praksis sas.

	//dwste ena paradeigma xrisis tou orou virtual 


	return 0;
}