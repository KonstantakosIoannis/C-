#include <iostream>

using namespace std;

class drink
{
	private :
		double price;
		string name;
	
	public :
		drink(string name , double price)
		{
			this->price=price;
			this->name=name;
		}
		
		double sumX(drink right)
		{
			//double summ;
			//summ=this->price + right.price;
			//return summ;
			
			return  this->price + right.price; 
		}
		
		double operator+(drink right)
		{
			return  this->price + right.price; 	
		}
		
		double operator-(drink a)
		{
			cout<<"dhelhedlfa"<<endl;
			double b= this->price+a.price;
			return b*0.9;
		}
		
		
		double operator+(double x)
		{
			return this->price+x;
		}
		
		void operator+(string a)
		{
			cout<<a<<endl;
			//return a;
		}
		
		double operator*(drink y)
		{
			cout<<"price : "<<this->price+y.price;
			cout<<"new price : ";
			return (this->price+y.price)*0.8;
		}
		
		drink operator/(drink right)
	{
		drink a("vodka",this->price+right.price);
		return a;
		
		//return drink("vodka",this->price+right.price);
	}
	
	void print()
	{
		cout<<this->name<<" "<<this->price<<endl;
	}
	
	void operator<<(string b)
	{
		this->name=b;
	}
	
	bool operator==(drink right)
	{
		if(this->price==right.price)return true;
		else return false;
	}
};

int main ()
{
	cout<<4+4<<endl;
	
	drink d1("coca cola" ,1.5);
	drink d2("fanta", 2);
	
	cout<<" Price Sum : ";
	cout<<d1+d2<<endl; 
	//cout<<d1.operator+(d2)<<endl;
	
	//cout<<d1.sumX(d2)<<endl;
	

	
	//sinoliki ekptosi 10%
	cout<<d1-d2<<endl;
	
	
	
	cout<<d1+1<<endl;
	cout<<d2+0.5<<endl;
	

	d2+"hello dfsd";
	
	

	cout<<d1*d2<<endl;
	

	drink d3=d1/d2;
	d3.print();
	
	
	double x=d1+d2;
	cout<<x;
	
	

	d3<<"Bacardi";
	d3.print();
	
	
	cout<<endl;
	bool a=d1==d3;
	cout<<a;
	
	return 0;
}