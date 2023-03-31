#include <iostream>

using namespace std;

class lemon
{
	private :
		static int howMany;
		
	public :
		lemon();
		
		void print()
		{
			cout<<howMany;
		}
		
};

lemon::lemon()
{
	howMany++;
}

int lemon::howMany = 0;

int main()
{
	lemon a1;
	lemon a2;
	lemon a3;
	lemon a4;
	lemon a5;
	
	a3.print();
	// a4.print();  //check
	
	return 0;
}
