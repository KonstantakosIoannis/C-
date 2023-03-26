#include <iostream>

using namespace std;

class swimmer
{
	private :
		int time;
	
	public :
		swimmer(int time){this->time=time;}
		void print(){cout<<this->time;}		
};

class runner
{
	private :
		int time;
	
	public :
		runner(int time){this->time=time;}
		void print(){cout<<this->time;}	
	
};

class cyclist
{
	private :
		int time;
	
	public :
		cyclist(int time){this->time=time;}
		void print(){cout<<this->time;}	
	
};

class triathlete:public runner, public cyclist, public swimmer
{
	private :
	
	public :
		triathlete(int timeS , int timeB , int timeR ):swimmer(timeS),cyclist(timeB),runner(timeR){}
};

int main ()
{
	triathlete t1(10,50,20);
	//t1.print();
	t1.cyclist::print();
	cout<<endl;
	t1.runner::print();
	cout<<endl;
	t1.swimmer::print();
	
	
	
	return 0;
}
