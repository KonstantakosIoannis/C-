#include <iostream>

using namespace std;

class person
{	private:
		string name;
		int age;
	
	public:
		person(){this->age=0;}
		person(int age){this->age=age;}
		
		
		//operator bool()const
		//bool operator()//DIFFERENT
		//{
		//	return this->age==0;
		//}
		
		
		
		operator int()const
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
