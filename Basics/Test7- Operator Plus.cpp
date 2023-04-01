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
	    
	    book operator+(const book &)const;
	    book operator+(const int  &)const;
	   	
};

book book::operator+(const int & right)const
{
	book temp("Y book ", this->price+right);
	return temp;
	

}

book book::operator+(const book & right)const
{
	book temp("X book" , this->price+right.price);
	return temp;
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
	
	book b5 = b1+b2;
	book b6 = b1+b3;
	book b7 = b5+b6;
	book b8 = b3+b4;
	
	b5.print();
	b6.print();
	b7.print();
	b8.print();
	
	b8=b8+2; //anatimisi
	b8.print();
	
	// b9=9+b1; check this error and try to fix it
	
	//check the following 3 lines
	//book b9 = b1+b2+b3+b4+9;  
	//book b10 = b5+b9+5+b4;    
	//book b11 = 5+b1+b2+b4;    
	
	return 0;
}
