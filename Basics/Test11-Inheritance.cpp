#include <iostream>

using namespace std;

class animal
{
	private :
		int age;
		string name;
	
	public :
		animal()
		{
			this->age=0;
			this->name=" ";
			cout<<"Default Animal"<<endl;
		}
		
		animal(string name , int age)
		{
			this->name=name;
			this->age=age;
			cout<<"New animal"<<endl;
		}
		
		~animal()
		{
			cout<<"Delete Animal"<<endl;
		}
		
		/////////////////////// functions getters and setters
		
		void print(){cout<<"My name is "<<this->name<<" and i am "<<this->age<<" years old"<<endl;}
		
		void ageSet(int age){this->age=age;}
		void nameSet(string name){this->name=name;}
		int ageGet(){return this->age;}
		string nameGet(){return this->name;}
};



////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

class dog : public animal
{
	private :
		string voice;
	
	public :
		dog(){cout<<"Default dog"<<endl;}
		dog(string voice){this->voice=voice; cout<<"Semi-Default Dog"<<endl;}
		dog(int age , string name , string voice):animal(name,age)//,voice(voice)
		{
			this->voice=voice;
			cout<<"New dog"<<endl;
		}
		
		~dog(){cout<<"Delete Dog"<<endl;	}
		
		/*
		void print()
		{
			cout<<this->voice<<endl;
		}
		*/
		
		void print()
		{
			//cout<<this->name; ERROR private - private
			cout<<"My name is "<<nameGet()<<" and i am "<<ageGet()<<" "<<this->voice<<endl;
		}
				
	
};







int main ()
{
	// animal debbug n check
	animal a1;
	a1.print();
	a1.ageSet(5);
	a1.nameSet("Rex");
	a1.print();
	cout<<a1.nameGet()<<a1.ageGet()<<endl;
	
	dog d1; // default animal - default dog
	dog d2("woof");// default animal & semi-default dog
	d2.print();  // kane chech me tin print mono tou animal
				// check me tin proti print tou dog
				// check me tin kanoniki print pou xrisimopoiei to ::animal
				
	dog d3(10,"lucy","woof woof");
	d3.print();
	
	
	
	return 0;
}
