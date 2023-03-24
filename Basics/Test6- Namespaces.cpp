#include <iostream>


/////////////////////////////////////////
namespace gobik
{
	void printMe()
	{
		std::cout<<"goodmorning"<<std::endl;
	}
}

void printMe()
	{
		std::cout<<"goodmorning"<<std::endl;
	}

///////////////////////////////////////////////////////////////

namespace part1
{
	namespace part2
	{
		void printMe()
		{
			std::cout<<"Hell0"<<std::endl;
		}
	}
	
}








//  using namespace gobik; 

int main()
{
	::printMe();
	
	gobik::printMe();
	
	/////////////////////
	
	part1::part2::printMe();
	
	
	
	return 0;
}
