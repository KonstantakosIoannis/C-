#include <iostream>

using namespace std;

class worker
{
	private :
		string name;
	
	public :
		worker(){cout<<"Default worker"<<endl;}
		worker(string name){this->name=name;   cout<<"New worker named : "<<this->name<<endl;}
	   ~worker(){cout<<"Deleting worker"<<this->name<<endl;}
	   //virtual ~ worker(){cout<<"Deleting worker "<<this->name<<endl;}
	   
	   virtual void addWorker(worker * myworker){}
};



class boss:public worker
{
	private :
		worker ** mylist;
		int howMany;
		int position;
		
	public :
		
		boss(string name , int howMany):worker(name)
		{
			this->howMany=howMany;
			mylist=new worker*[howMany]; 
			cout<<"New boss"<<endl;   
			position=0;
		}
		
		void addWorker(worker * myworker)
		{
			cout<<"One more worker in the list"<<endl;
			mylist[position]=myworker;
			++position;
		}
			
		
		~boss()
		{
			cout<<"Deleting boss "<<endl;
			if(mylist!=NULL)
			{
				delete [] mylist;
				mylist=NULL;
				cout<<"Deleting list"<<endl;
			}
		}
		
};

int main()
{
	
	worker * w1 = new worker;
	delete w1;
	cout<<endl<<endl;
	
	worker * w2 = new worker("Bill");
	delete w2;
	cout<<endl<<endl;
	
	boss * b1 = new boss("Kostas",3);
	delete b1;
	cout<<endl<<endl;
	
	worker * w3 = new boss("John",2);
	delete w3;
	cout<<endl<<endl;

	boss * b2 = new boss("Jim",2);
	worker * w4 = new worker();
	worker w5("Lola");
	
	b2->addWorker(w4);
	b2->addWorker(&w5);
	
	
	delete b2;
	delete w4;
	

		
	
	//virtual distructor test
	worker * staff[3];
	staff[0]=new worker("hoho");
	staff[1]=new worker("hehe");
	staff[2]=new boss("lele",2);
	
	staff[2]->addWorker(staff[0]);
	//PROSOXI edw gia na treksei auti i sanartisi ekana kai mia idia alla virtual
	// sto progono. Den kanei kati apla iparxei gia na mporei na deiksei ekei o pointer 
	// kai na paei meta sto apo katw epipedo klironomikotitas
	
	for (int i=0; i<3; i++)delete staff[i];
	
	
	return 0;
}
