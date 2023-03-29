# include <iostream>

using namespace std;

int main () {
	
	float x ;
	
	cout<<"give me a number : ";
	cin>>x;
	
	try {         
	 if (x !=0){	
	 	cout<<float(2/x)<<endl;     
	 }
	 else throw (x);    
	}
	
	
	catch (float x)
	{    /
		cout<<x<<" is not valid"<<endl;   
	}
	
	
	
	return 0;
}
