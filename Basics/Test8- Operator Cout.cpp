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
	    
	    friend book operator + (int  left , const book & right )
	    {
	    	return book(right.name,right.price+left);
		}
	    
	    /*
	    friend void operator<<(ostream & os , const book & right)
	    {
	    	os<<"Hello my price is "<<right.price<<endl;  // h alliws
	    	cout<<"Hello my price is "<<right.price<<endl;
		} // edw den paizw me this giati pleon den eimai mesa stin klasi
		// mporei na grafetai entos klasis i sanartisi kai na blepei ta pedia tin epeidi einai friend
		// omos den apotelei melos tis
		*/
		
		friend ostream & operator <<(ostream & os ,  book & right)
		{
			os<<"Hello my price is "<<right.price<<endl;
			return os;  // den exei simasia ama tha balw os i cout 
		}
};


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
	
	//cout<<b4;
	cout<<b4<<endl;  // me tin prwti ilopoihsh den trexei giati exw void
	
	b1.print();
	book b5=10+b1;
	b5.print();
	
	return 0;
}
