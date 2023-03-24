#include <iostream>

using namespace std;

template <typename T>
class person
{
	private :
		T grade;
	
	public :
		person(T grade)
		{
			this->grade=grade;
		}
};






template <typename T , int N>
class book
{
	private :
		T pinakas[N];
	
	
};


int main()
{
	person<int> p1(5);
	
	book<int,10> b1;
	
	
	return 0;
}