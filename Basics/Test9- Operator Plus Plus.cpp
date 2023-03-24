#include <iostream>


using namespace std;

class book
{
	private :
		string name;
		int price;
		
	public :
		book();
		book(string , int);
	   ~book();
	   
	    void print();
		
		book & operator++();    
		const book operator++(int);
	
};

const book book::operator++(int)//metathematikos x++
{
	book temp(this->name , this->price);//dimiourgia prosorinou antikeimenou
	this->price=this->price+9;
	return temp;
}

//einai pio grigoros giati den exw dimiourgia prosorinou antikeimenou
book & book::operator++()//prothematikos ++x
{
	this->price=this->price+5;
	return *this;
}

book::~book()
{
	cout<<this->name<<" deleted"<<endl;
}

void book::print()
{
	cout<<this->name<<" costs "<<this->price<<endl;
}

book::book(string name , int price)
{
	this->name=name;
	this->price=price;
	cout<<"A new book is made"<<endl;
}

book::book()
{
	this->name="no name";
	this->price=0;
	cout<<"A default book is made"<<endl;
}

int main()
{
	book b1;
	book b2;
	book b3("Harry Potter",10);
	book b4("GoT",5);
	
	++b4;
	b4.print();
	
	b4++;
	b4.print();
	
	book b5 = b4++;
	b5.print();
	b4.print();
	
	
	
	
	return 0;
}
