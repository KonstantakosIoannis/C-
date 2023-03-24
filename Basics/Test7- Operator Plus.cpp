#include <iostream>

// operator +(book+book) kai epistrefei book
// operator +(book+int)  kai epistrefei book


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
	
	// an de thelame na dimiourgisoume kainourgio biblio apla na auksisw tin timi 
	// tou eautou mou (b0=b0+5;) pws tha ginotan kalitera i parapanw ilopoihsh?
	// askisi
	
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
	
	// b9=9+b1; AUTO de ginetai akoma 
	// GIATI??
	// to be implemented when friendly . . . 
	
	// askisi 2 : na epistrefei int kai oxi book
	
	//askisi 3 :
	//book b9 = b1+b2+b3+b4+9;  // ginete?
	//book b10 = b5+b9+5+b4;    // ginete? giati? afou to 9+b1 de ginetai parapanw
	//book b11 = 5+b1+b2+b4;    // ginete? giati oxi?
	
	return 0;
}
