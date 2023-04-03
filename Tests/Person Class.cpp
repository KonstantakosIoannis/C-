#include <iostream>

using namespace std;

class person
{
	private :
		double salary;
		int age;
		string name;
		//person * this;
		
	
	public :
		//constructors
		
		// stin arxi iparxei ALLA an ftiaksw ena custom constructor (diko mou)automata diagrafetai
		// kai prepei na ton ftiaksw egv apo tin arxi
		//default (ton grafw monos mou otan ftiaksw mia klash)
		person()
		{
			cout<<"default"<<endl;// de xreiazetai (to kanw mono gia tsekarisma)
			this->name="baby";
		}
		
		
		person(int age , string name , double salary)
		{
			age=5;
			this->age=age;
			this->name=name;
			this->salary=salary;
			
		
			//cout<<"AGE :::: "<<age<<endl;
		}
		
		//person(int myage , string myname , double mysalary)
		//{
		//	age=myage;
		//	name=myname;
		//	salary=mysalary;
		//	//return age;
		//}
		
		person(int x , string y , double z , int t)
		{
			age=x;
			name=y;
			salary=z;
			//return age;
			cout<<t<<endl;
		}
		
		person(int myage)
		{
			age=myage;
		}
		
		person(string x, int y)
		{
			salary=500;
			age=y;
			name=x;	
		}
		
		person(int x , string s)
		{
			
		}
		
		
		
		//functions
		void print()
		{
			cout<<age<<" "<<name<<" "<<salary<<endl;
			//return age;
		}
		
		int getAge()
		{
			return age;
		}
		
		//destructor - ENAS KAI MONADIKOS Kai XORIS orismata
		~person()
		{
			cout<<"Deleting "<<this->name<<endl;
		}
		
		
		
		
		
};



class boy
{
	private:
		
	public :
		boy(){}
		
		boy(int x)
		{
			////
		}
		
};


int main()
{
	boy tim;
	
	
	int x;
	string y;
	person kostas(25,"Kostas",2000.1);
	person giannis(275);
	
	kostas.print();
	cout<<kostas.getAge()<<endl;
	giannis.print();
	
	person petros("Petros",30);    //to be implemented
	petros.print();
	
	person kostasERROR(92,"Kostas",2000.1 , 9);
	kostasERROR.print();
	
	
	
	person jim;//default constructor
	person pinakas[10];//default constuctor
	
	person * nikosPTR = new person(50,"nikos",5000.5);
	nikosPTR->print();//stous pointers kalitera -> pio eukolo kai grigoro
	(*nikosPTR).print();//akribos to idio
	
	person * pinakasX = new person[10];
	
	delete nikosPTR;
	delete [] pinakasX;
	
	return 0;
}