#include <iostream>

using namespace std;

class animal{};

class dog:public animal{};


int main()
{
	int x=10;
	double y = 10.5;
	
	int x2=(int)y;
	int x3=y;// automatic casting
	
	cout<<x<<endl<<y<<endl<<x2<<endl<<x3<<endl;
		
	///////////////////////////// class casting
	
	class animal a1;
	class dog d1;
	
	animal a2 = d1;
	animal a3 = (animal)d1;
	
	//dog d2=(dog)a1; ERROR 
	
	dog * dPtr = (dog*)&a1;
	//not an ERROR but is A LOGICAL MISTAKE
	
	
	// if it is necessary do this instead : 
	dog dd2 = * static_cast <dog*> (&a1);
	
	
	return 0;
}
