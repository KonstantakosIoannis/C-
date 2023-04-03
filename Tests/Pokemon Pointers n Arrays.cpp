#include <iostream>

//#include <string>



using namespace std;

class pokemon{
	
	private:
	string name;
	unsigned int level;
	int hpoints;
	string voice;
	string * foodlist;//=0x851785
	unsigned int i;
	
	public:

pokemon(){
	cout<<"new baby pokemon"<<endl;
	this->hpoints=0;
	this->foodlist=NULL;
	this->level=0;
}
pokemon(string name, unsigned int level, int hpoints, string voice,){
	this->name=name;
	this->level=level;
	this->hpoints=hpoints;
	this->voice=voice;
	foodlist=new string[3];
	this->i=0;
	cout<<"new pokemon"<<endl;
}

void setFoodlist(string food)
{
	if(i<3)
	{
		foodlist[i]=food;
		++i;	
	}	
}

void printFoodlist()
{
	for(unsigned int i=0; i<3; i++)cout<<foodlist[i]<<endl;
}

~ pokemon()
{
	cout<<"delete pokemon"<<endl;
	if(foodlist!=NULL)
	{
		delete [] foodlist;
		foodlist=NULL;
	}	
}


};

int main(){
	pokemon MyFirstPokemon("pikatsou",10,5,"pika");
	
	MyFirstPokemon.setFoodlist("Burger");
	MyFirstPokemon.setFoodlist("Pizza");
	MyFirstPokemon.setFoodlist("Kotopoulo");
	MyFirstPokemon.printFoodlist();
	
	
	pokemon *ppointer=new pokemon("bulbasaur",4,3,"pika");
	pokemon *bppointer=new pokemon();
	
	pokemon *table=new pokemon [3];
	table[0]=*bppointer;
	table[1]=*ppointer;
	table[2]=MyFirstPokemon;
	
	delete [] table;
	table=nullptr;
	
	pokemon table2[3]={MyFirstPokemon, *ppointer, *bppointer};
	
	pokemon * table3[3]={ppointer,bppointer,table};
	
	pokemon ** table4=new pokemon * [3];
	table4[0]=ppointer;
	
	delete []table4;
	delete bppointer;
	
	return 0;
};
	

