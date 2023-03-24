#include <iostream>
#include <functional>
#include <thread>

using namespace std;

class person
{
	private :
		int age;
	
	public :
		int triple(){return age*3;}
		person(int age){this->age=age;}
};

int main()
{
	
	person john(5);
	
	function<int()> triX = bind(&person::triple,john);	
	
	cout<<triX();
	
	thread thX = thread(triX);
	
	
	return 0;
} 
// c++ 11 or VISUAL STUDIO
