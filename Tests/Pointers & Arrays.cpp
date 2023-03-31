#include <iostream>

using namespace std;

int main()
{
	int a[5];
	//int a[];  ERROR
	a[8]=12; // not an ERROR but its a big mistake
	
	
	int i;
	cin>>i;  
	int beta [i];  // not an ERROR but its a big mistake
	
	
	/////// POINTERS //////////////
	
	int alpha = 10;
	
	int * alphaPTR = &alpha;
	
	char * betaPTR = 0; // NULL   nullptr        
	
	int ** alphaPTR_PTR = &alphaPTR;
	
	int *** alpha3PTR; //toooo much
	
	
	
	
	
	
	int myArray[5];
	myArray[0]=2021;
	myArray[3]=2022;
	cout<<myArray[0]<<endl;	
	
	int * myArrayPTR = &myArray[0];
	
	cout<<myArrayPTR<<endl<<&myArray[0]<<endl<<myArray<<endl<<&myArray<<endl;
	
	cout<<*myArrayPTR<<endl;   
	cout<<&myArrayPTR<<endl;  
	cout<<*(myArrayPTR+3);
	
	
	int delta [] = {1,2,3};
	
	int * delta2 = new int [3];  
	delta2[0]=5;
	
	// int * delta  = {1,2,3}; ERROR
	// int delta  []  = new int  [3];
	
	
	delete [] delta2;
	delta2=NULL;
	delta2 = new int[100];
	
	delete [] delta2;
	//delete [] delta2; ERROR double delte . run time error
	
	int ** epsilon = new int * [10];
	epsilon[0] = new int [4];
	
	
	int * ypsilon [3];
	ypsilon[0]=new int [0];
	//NEVER forget to delete everything you have NEW
	
	return 0;
}
