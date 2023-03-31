#include <iostream>

using namespace std;
class car
{
	private :
		string name;
		double price;
		double speed;
		string colour;
		bool broken;
	
	
	public: 

	car(string name, double price, double speed)
		{
			
			this->name=name;
			this->price=price;
			this->speed=speed;
			this->colour="Blue";
		
		
		}
		
		car(string name, double price, double speed, string colour)
		{
			
			this->name=name;
			this->price=price;
			this->speed=speed;
			this->colour=colour;
			
		
		
		}
		
		car(string name, double speed)
		{
			
			this->name=name;
			this->speed=speed;
			this->colour="Black";
		}
		
		car(bool broken)
		{
			//this->name="Volvo";
			this->broken=broken;
			if(this->broken==true)cout<<"This car is broken"<<endl;
		}
};
		
int main()
{
	car c1("Scania" , 120000 , 140);  //brand price speed
	car c2("Ferrari" , 3500000 , 320 , "Red");// ..... colour
	car c3("Datsun",75);// brand - max speed
	car c4(-8524.6325);// broken 
	car c5(0);
	

	
	
	
	return 0;
}
