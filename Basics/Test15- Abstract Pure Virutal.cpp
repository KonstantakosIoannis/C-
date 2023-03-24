#include <iostream>

using namespace std;

class animal
{
	private :
		int age;
		string name;
	
	public :
		animal(){cout<<"animal defaut"<<endl;}
		animal(string name , int age){this->name=name; this->age=age; cout<<"animal"<<endl;}
		~animal(){cout<<"deleting animal"<<endl;}
		
		virtual void print()=0;
		
};


class dog:public animal
{
	private :
		string voice;
	
	public :
		dog(string name , int age , string voice):animal(name,age)
		{
			this->voice=voice;
			cout<<"dog"<<endl;
		}
		
		void print()
		{
			cout<<"Now we have a class"<<endl;
		}
		
		~dog(){cout<<"deleting dog"<<endl;}
};

int main()
{
	//animal a;
	dog d("lucy",10,"woof");
	
	
	
	
	return 0;
}
