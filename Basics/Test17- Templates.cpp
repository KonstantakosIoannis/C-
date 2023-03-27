#include <iostream>

using namespace std;

template <typename T>
void print(T  a , T  b)
{
	cout<<a<<" "<<b<<endl;
}




template <typename T , typename R>
void print2(T a, R b)
{
	cout<<a<<" "<<b<<endl;
}


template <typename T>
void go(T a)
{
	cout<<"Default go "<<endl;
}

//template <typename T>  //inline is not templated
inline void go(string a)
{
	cout<<"inline"<<endl;
}



int main()
{
	print(5,5);
	print(1.2,1.2);
	print("a;lkhsdj","lakjsdf");
	//print(5,5.1); error !! no match
	
	
	print2(5,5.1);//SOLVED!!
	print2("Hello",14);
	
	
	
	go(5);
	go(5.5);
	go("Hello");// 
	string a="Hello";
	go(a);
	
	return 0;
}
