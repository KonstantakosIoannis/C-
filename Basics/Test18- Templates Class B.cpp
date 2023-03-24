#include <iostream>

using namespace std;

class pokemon{
};

template <typename T, typename S>
class person
{
	private :
		T data;
		S  next;
		
	public :
		person(){}
		
		person(T data , S next)
		{
			this->data=data;
			this->next=next;
		}

};

int main()
{
	person <int , pokemon>p1;
	person<int, person<int ,int>>p2;
	
	
	return 0;
}