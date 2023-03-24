#include <iostream>

void print(int);

void printGo(void(*printPTR)(int) , int data , int times)
{
	for (unsigned i=0; i<times; i++)
	{
		printPTR(data);
		
	}
}

int main()
{
	print(5);
	std::cout<<std::endl;
	
	void (*printPTR) (int);  
	printPTR = print;
	printPTR(11);
	std::cout<<std::endl;

	printGo(print , 9 , 9);
	
	printGo(printPTR, 9 , 9);
		
	return 0;
}

void print (int a)
{
	std::cout<<a;
}
