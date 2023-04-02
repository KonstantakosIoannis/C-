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
	    book addBooks(const book &)const;
		book operator+(book &);	    
		book operator+(const int)const;
		book operator+(string){};
		//int operator+(int); ERROR
		
		int operator-(book &);
		
		book & operator++(); // PRO
		
		const book  operator++(int);//META
		
		void operator>>(int);
		
		book operator<<(int);
		
		
	

		friend int operator+(const int ,const book);
		friend ostream & operator<<(ostream & , book & );
		
};

book book::operator<<(int right)
{
	return book(this->name, this->price+5000);
}



void book::operator>>(int right)
{
	this->price=right;
}

ostream & operator<<(ostream & os , book & right)
{
	os<<right.name<<" costs "<<right.price<<endl;
	return os;
}

int operator+(const int left ,const book right)
{
	return(left+right.price);
	
}

const book book::operator++(int)
{
	book temp(this->name , this->price);
	++this->price;
	this->name="Gell";
	return temp;
	
}

book & book::operator++()
{
	++this->price;
	this->name="Gell";
	return *this;
}



book book::operator+(const int right)const
{
	return book(this->name , this->price+right);
}

int book::operator-(book & right)
{
	return this->price-right.price;
}

book book::operator+(book & right)
{
	return book(this->name, this->price+right.price);
}

book book::addBooks(const book & right)const
{
	book temp(this->name, this->price+right.price);
	
	return temp;
	
	//return book(this->name, this->price+right.price);

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

/////////////////////////////////////////////////////////////////////////////////////

// operators +-*/[]<><<>>()=^%
// .   
// ::
//sizeof()
// a?b:c


int main()
{
	book b1;
	book b2;
	book b3("Harry Potter",10);
	book b4("GoT",5);
	
	book b5=b3.addBooks(b4);
	book b7=b3.operator+(b4);
	
	book b6=b3+b4;
	
	
		
	
	b5.print();
	b6.print();
	b7.print();
	
	cout<<b3-b4<<endl;
	
	book b8 = b1+10;
	b8.print();
	
	
	int i=5;
	cout<<++i;
	cout<<i++;
	

	
	book b9=++b8;
	b9.print();
	
	++b9;
	b9.print();
	
	book b10 =b1++;
	b10.print();
	b1.print();
	
	cout<<"         "<<5+b1<<endl;
	
	cout<<endl<<endl;
	cout<<b1<<endl<<endl;
	
	cout<<5+b1+b2+10<<endl;
	book bx= b1+5+b2+b5; 
	bx.print();
	
	
	b1>>5000;
	book by=b1<<5000;
	 
	
	b1.print();
	by.print();
	
	cout<<b1+5;

	return 0;
}
