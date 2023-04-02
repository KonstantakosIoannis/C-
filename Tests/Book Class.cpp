#include <iostream>

using namespace std;

class book
{
	private :
		int price;
		string name;
		int pagesNumber;
		
		int * pages;
		
		
	
	
	public :
		static int howMany;
		
		void print()const;       
		
	
		book();
		
		//book():name("NO "),price(5)
		//{
		//	cout<<"  "<<endl;
		//}
		
		//book(string name=" ", int price = 0;)    
		//{
		//	this->name=name;
		//	this->price=price;
		//	cout<<"Default constructor alike"<<endl;
		//}
		
		book(string , int);
		book(string name)
		{
			this->name=name;
			
			cout<<"A new book with constructor Number 2"<<endl;
			howMany++;
			this->pages= new int[20];
		}
		
		
	  ~ book();
};

int book::howMany=0;

book::~book()
{
	cout<<"Deleting "<<this->name<<endl;
	howMany--;
	
	if(this->pages!=NULL) delete [] pages;
	
}

book::book()
{
	cout<<"default"<<endl;
	this->name="No name";
	this->price=0;
	howMany++;
	this->pagesNumber=0;
	this->pages=NULL;
}

book::book(string name , int price)
{
	this->name=name;
	this->price=price;
	cout<<"A new book"<<endl;
	howMany++;
	this->pagesNumber=10;
	this->pages=new int [pagesNumber];
}


void book::print() const
{
	cout<<name<<" costs "<<price<<endl;
}



int main()
{
	const book x("adfd",5);
	x.print();
	
	
	book b1("Harry potter",10);  
	b1.print();
	
	book b2;
	b2.print();
	
	book b3("Lord");
	b3.print();
	
	cout<<b1.howMany<<endl;
	cout<<b2.howMany<<endl;
	cout<<b3.howMany<<endl;
	
	book * b4 = new book();
	book * b5 = new book("GoT",22);
	
	cout<<b1.howMany<<endl;
	
	b4->print();
	//(*b4).print();
	
	
	book library [4]; 
	library[0]=b1;
	library[1]=book();
	library[2]=book("adfd",5);
	library[3]=*b4;
	
	book * library2 = new book[2]; 
	library[0]=b2;
	library[1]=*b5;
	
	delete [] library2;
	
	book * library3[2];
	library3[0]=b4;
	library3[1]=b5;
	
	book ** library4 = new book * [2];
	library4[0]=b4;
	library4[1]=b5;
	
	delete[] library4;
	
	
	
	delete b4;
	
	cout<<b1.howMany<<endl;
	
	delete b5;
	
	// delete b5; run time error
	
	return 0;
}
