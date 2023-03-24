#include <iostream>

using namespace std;

class person
{
	private :
		int age;
		string name;
		string * friends ;
		
	public :
		person();
		person(int , string);
	   ~person();
	   
		void print();
		void printFriends();
		
		string & operator[](int);
		
		// copy constructor
		person (const person &);
		
		person & operator=(const person &);
		//ginetai kai me void alla tote tha eixa thema otan ekana p1=p2=p3;  etc...
};

person & person::operator=(const person & src)
{
	if(&src==this) return *this;
	if(friends!=NULL) delete [] friends;
	this->age=src.age;
	this->friends = new string[3]; 
	memcpy(friends,src.friends,3*sizeof(string));
	return *this;
	
}

person::person(const person & src)
{
	this->age=src.age;
	this->friends = new string[3]; 
	memcpy(friends,src.friends,3*sizeof(string));
}



string & person::operator[](int position)
{
	return friends[position];
}


void person::printFriends()
{
	for (int i=0; i<3; i++)cout<<friends[i]<<endl;
}

void person::print()
{
	cout<<"My name is "<<this->name<<" and i am "<<this->age<<endl;
}

person::~person()
{
	if(this->friends!=NULL) delete []friends;
}

person::person(int age , string name)
{
	this->name=name;
	this->age=age;
	friends=new string [3];
}

person::person()
{
	this->name=" ";
	this->age=0;
	friends=NULL;
}

int main()
{
	person john(15,"john");
	john[0]="tom";
	john[1]="tim";
	john[2]="tam";
	john.print();
	john.printFriends();
	cout<<john[1]<<endl;
	
	person p1(10,"p1");
	p1[0]="LOLA";
	
	person p2=p1;
	p2[0]="MARGARITA";
	
	person p3(p1);
	p3[0]="ELENI";
	
	//check with and without copy constructor 
	cout<<p1[0]<<endl<<p2[0]<<endl<<p3[0]<<endl;	
	
	p1=p2=p3;
	p1=p1;
	
	
	return 0;
}
