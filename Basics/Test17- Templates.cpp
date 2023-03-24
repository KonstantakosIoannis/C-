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

//template <typename T>   SOS otan kanw kati inline (template) DEN to kanw template
inline void go(string a)
{
	cout<<"inline"<<endl;
}



int main()
{
	print(5,5);
	print(1.2,1.2);
	print("a;lkhsdj","lakjsdf");
	//print(5,5.1); ERROR diaforetika orismata
	
	
	print2(5,5.1);//twra ola ok
	print2("Hello",14);
	
	
	
	go(5);
	go(5.5);
	go("Hello");// den to pairnei ws string
	string a="Hello";
	go(a);
	
	return 0;
}
