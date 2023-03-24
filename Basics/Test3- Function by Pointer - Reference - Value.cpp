#include <iostream>

using namespace std;

// by value
void run ( int x)
{
	x=x*100;
}


//by pointer
void run ( int * x)
{
	*x=*x*100;
}


//by reference
void run2 ( int & x)
{
	x=x*100;
}


int main()

{
	int x = 10;
	
	run(x);
	cout<<x<<endl;
	
	run(&x);
	cout<<x<<endl;
	
	run2(x);
	cout<<x<<endl;
		
		
	return 0;
}
