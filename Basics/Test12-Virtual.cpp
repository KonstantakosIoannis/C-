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
		
		//virtual void print(){cout<<"My name is "<<this->name<<" and i am "<<this->age<<" years old"<<endl;}
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
		
		void print() // override
		{
			//cout<<this->name; ERROR private - private
			cout<<"My name is "<<nameGet()<<" and i am "<<ageGet()<<" years old "<<this->voice<<endl;
		}
				
	
};


void display(animal & alpha) 
{
	alpha.print();
}




int main ()
{
	
	
	animal * alpha = new animal("Rex",10);
	dog * doggo = new dog(10,"lucy","woof woof");
	
	alpha->print();
	doggo->print();
	
	animal * beta = doggo;
	beta->print(); // animal print
	
	// arrays example
	animal * pin[2];
	pin[0]=alpha;
	pin[1]=beta;
	cout<<endl<<endl;
	pin[0]->print();
	pin[1]->print();
	cout<<endl<<endl;
	
	
	delete alpha;
	delete doggo;
	
	
	animal delta("Rex",10);
	dog sigma(10,"lucy","woof woof");
	
	display(delta);
	display(sigma);
	
	
	return 0;
}
