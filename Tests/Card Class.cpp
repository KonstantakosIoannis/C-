#include <iostream>

using namespace std;

class card
{
	private :
		int hp;
		int attack;
		string name;
	
	public :
		
		card()
		{
			cout<<"Default "<<endl;
		}
		
		card(int hp, int attack, string name)
		{
			cout<<"New card"<<endl;
			this->name=name;
			this->attack=attack;
			this->hp=hp;
		}
		
		void print()
		{
			cout<<this->name<<" has "<<this->attack<<" attack points"<<endl;
		}
		
		
		~card()
		{
			cout<<"Destroy card"<<endl;
		}
};

int main()
{
	
	card c1(10,10,"monster 1");
	card c2(10,10,"monster 2");
	card c3(10,10,"monster 3");
	card c4(10,10,"monster 4");	
	
	card * c5 = new card(20,5,"monster 5");
	card * c6 = new card(20,10,"monster 6");
	
	
	c1.print();
	c5->print();
	
	int pinakas[10];
	int * pinakas2= new int[10];
	
	delete [] pinakas2;
	
	
	//////////////////////
	
	card deck[10];
	deck[0]=c1;
	deck[1]=c2;
	deck[2]=c3;
	deck[3]=c4;
	deck[4]=*c5;
	
	deck[2].print();
	
	card * deck2[2];
	deck2[0]=c5;
	deck2[1]=c6;
	
	deck2[1]->print();
	
	
	
	
	card * deck3 = new card[5];
	deck3[3]=c1;
	deck3[0]=c2;
	
	delete [] deck3;
	
	//////////////////////////
	
	card ** deck4 = new card* [3];
	deck4[0]=c6;
	
	
	delete [] deck4;
	
	
	
	
	delete c5;
	
	return 0;
}