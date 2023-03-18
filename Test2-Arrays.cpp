#include <iostream>

using namespace std;

int main()

{
		
	int * y[5];
	
	int a1=1;
	int a2=10;
	int a3=100;
	int a4=1000;
	int a5=10000;
	
	int * b1 = &a1;  
	int * b2 = &a2;
	int * b3 = &a3;
	int * b4 = &a4;
	int * b5 = &a5;
	
	y[0]=b1;
	y[1]=b2;
	y[2]=b3;
	y[3]=b4;
	y[4]=b5;
	
	cout<<*y[1];
	
		
	return 0;
}
