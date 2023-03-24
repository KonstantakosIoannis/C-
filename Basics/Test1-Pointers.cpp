#include <iostream>

using namespace std;

int main()



{

	int a=5;
	int * aP = &a;
	int ** aP2  = &aP;
	
	cout<<a<<endl;   
	//cout<<*a;       
	cout<<&a<<endl;   
	
	cout<<aP<<endl;   
	cout<<*aP<<endl;  
	cout<<&aP<<endl; 
	cout<<*&aP<<endl; 
	cout<<&*aP<<endl; 
	
	cout<<aP2<<endl;   
	cout<<*aP2<<endl;  
	cout<<&aP2<<endl;  
	cout<<*&aP2<<endl;  
	cout<<&*aP2<<endl;
	
	
	
	return 0;
}
