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
	// MONO me visual studio (protinetai)

	animal* aPTR = new dog;

	cout << typeid(aPTR).name() << endl;
	cout << typeid(*aPTR).name() << endl;  // kane tsek me kai xoris virtual

	cout << (typeid(animal) == typeid(*aPTR)) << endl;
	// edw tsakarei me ena true-false an to *aPTR einai tipou animal




	return 0;
}