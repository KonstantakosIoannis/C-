#include <iostream>

using namespace std;

class myfile
{
	private :
		int * pin;
		int pinSize;
	
	public :
		myfile(int pinSize)
		{
				this->pinSize=pinSize;
				this->pin=new int[this->pinSize];
				cout<<"New file"<<endl;
		}	
		
		myfile(const myfile & src)//copy constructor
		{
			this->pinSize=src.pinSize;
			this->pin=new int[this->pinSize];
			for(int i=0; i<pinSize; i++)this->pin[i]=src.pin[i];
			cout<<"Copy con"<<endl;
		}
		
		myfile  (myfile && src)//move constructor
		{
			cout<<"Move "<<endl;
			this->pin=src.pin;
			this->pinSize=src.pinSize;
			
			
			src.pinSize=0;
			src.pin=NULL;
			
		}
		
		myfile & operator=(myfile && src)
		{
			cout<<"Move ="<<endl;
			
			if (this == &src) return *this;
   
      		delete[] pin;
      		this->pinSize=src.pinSize;
      		this->pin=src.pin;
      
      		src.pinSize=0;
      		src.pin=NULL;
			
			
			return *this;
			
		}
		
		~myfile()
		{
			cout<<"Delete"<<endl;
			if(pin)
			{
				delete [] pin;
				pin=NULL;
			}
		}
		
		void pinFill()
		{
			for(int i=0; i<pinSize; i++)
			{
				pin[i]=i+10;
			}
		}
		
		
		void print()
		{
			for(int i=0; i<pinSize; i++)
			{
				cout<<pin[i]<<endl;
			}
		}
		
};

myfile go()
{
	return myfile(5);
}
int main()
{
	myfile(5);
	
	myfile g=go();
	
	myfile f(5); 
	f.pinFill();
	f.print();
	
	myfile s=f;
	cout<<endl<<endl;
	s.print();
	
	f=myfile(5);  //move operator
	
	
	
	
	
	return 0;
}
