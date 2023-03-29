#include <iostream>

using namespace std;

class animal
{
public :
	//virtual void print(){}
};

class dog :public animal
{

};

int main()
{
	

	animal* aPTR = new dog;

	cout << typeid(aPTR).name() << endl;
	cout << typeid(*aPTR).name() << endl;  //check with and without virtual 

	cout << (typeid(animal) == typeid(*aPTR)) << endl;





	return 0;
}
