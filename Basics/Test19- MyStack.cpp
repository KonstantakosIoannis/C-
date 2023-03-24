#include <iostream>

using namespace std;

template <typename T>
class myStack
{
	private :
		T data;
		myStack * next;
		
	public :
		T getData()const{return data;}
		
		myStack * getNext(){return next;}
		
		myStack(){this->next=NULL;}
		myStack(T data , myStack * next)
		{
			this->data=data;
			this->next=next;
		}
};

int main()
{
	
	myStack <int> ms1;
	myStack <int> ms2(20,&ms1);
	myStack <int> ms3(30,&ms2);
	myStack <int> ms4(40,&ms3);
	
	
	
	
	return 0;
}
