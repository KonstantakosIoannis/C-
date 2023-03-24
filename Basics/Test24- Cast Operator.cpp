#include <iostream>

using namespace std;

class person
{	private:
		string name;
		int age;
	
	public:
		person(){this->age=0;}
		person(int age){this->age=age;}
		
		
		//operator bool()const// telestis metatropis tipou. epistrefei bool metabliti
		//bool operator()// kai oxi etsi
		//{
		//	return this->age==0;
		//}
		
		
		
		operator int()const// telestis metatropis tipou. epistrefei bool metabliti
		{
			return this->age;
		}
		
		
		
};

int main()
{
	
	person p1;
	person p2(10);
	
	cout<<(p2)<<endl;
	cout<<(p1)<<endl;
	
	
	return 0;
}