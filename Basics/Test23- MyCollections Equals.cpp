#include <iostream>
#include <set>

using namespace std;

class banana
{
	private :
		int weight;
		int length;
		string name;
	
	public :
		banana()
		{
			cout<<"Default Banana"<<endl;
			this->weight=0;
			this->length=0;
			this->name="Laiki";
		}
		
		banana(int weight , int length , string name)
		{
			cout<<"Banana"<<endl;
			this->weight=weight;
			this->length=length;
			this->name=name;
		}
	
		inline const int getWeight()const{return this->weight;}
		inline const int getLength()const{return this->length;}
		inline const string getName()const{return this->name;}
		
};

class howBig
{
	private://
	public :
		bool operator ()(const banana & a , const banana & b){return a.getWeight()<b.getWeight();}//auksousa
		
		//bool operator ()(const banana & a , const banana & b){return a.getWeight()>b.getWeight();}//fthinousa
		
		//bool operator ()(const banana & a , const banana & b){return a.getLength()<b.getLength();}//auksousa
		
		//bool operator ()(const banana & a , const banana & b){return a.getLength()>b.getLength();}//fthinousa
};

int main()
{
	banana b1;
	banana b2(10,10,"Bajella");
	banana b3(20,200,"Dole");
	banana b4(40,100,"Chiquita");	
	
	set<banana> mikroKalathi;
	//mikroKalathi.insert(b1);   //ERROR    ??giati??
	
	set<banana,howBig> kalathi;  //equal - compar - sigrisi
	
	kalathi.insert(b1);
	kalathi.insert(b2);
	kalathi.insert(b3);
	kalathi.insert(b3);//monadika stoixeia
	kalathi.insert(b4);
	
	for (set<banana,howBig>::iterator i=kalathi.begin(); i!=kalathi.end(); ++i)//protimame auto oso ginetai
	//for(auto i=kalathi.begin(); i!=kalathi.end(); ++i) auto=set<banana,howBig>::iterator
	{
		//1os tropos NEW ONE
		banana temp=*i;
		cout<<temp.getName()<<endl;
		
		//2os tropos
		cout<<i->getName()<<endl;
	}
	
	
	
	
	
	return 0;
}