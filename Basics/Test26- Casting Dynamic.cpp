#include <iostream>

using namespace std;
  

class animal
{
	public :
    	virtual void print(){cout << "animal" << endl;} // bgale to virtual void kai kane tsek
};
  
class dog : public animal 
{
	public :
		//void print(){cout << "dog" << endl;}
};

class cat : public animal 
{
	public :
		void print(){cout << "cat" << endl;}
};
  

  

int main()
{
	animal a1;
    dog d1;
    cat c1;
    
    animal * aPTR = dynamic_cast<animal*>(&d1);
    // edw metatrepw ton pointer tou d1 se pointer tipou animal
    // pragma to opoio einai eukolo kai ginetai panta. trexei akoma ki an den exw virtual thn print tou animal
    //ayto den einai dynamic casting
  	
  	
  	
  	cat * cPTR = dynamic_cast<cat*>(&d1);
  	
	// edw prospathw na metatrepsw se cat ena dog DEN GINETAI - omoiws de ginetai kai to cat se dog
  	// tsekare ti ginetai an i void print tou animal den einai virtual
  	//TIP oti exw sta aristera(cat*) tha exw kai sta <>
  
  	//thimizoume oti an den petixei to casting tha epistrafei enas nullptr
  	// pleon i c++ sou bgazei kai warning oti den petixe to cast
    
	if(cPTR==nullptr) cout<<"null"<<endl;
    else cout<<"not null"<<endl;
   	
   	
   	
   	
   	
   	dog * dPTR = dynamic_cast<dog*>(&a1);
  	if(dPTR==nullptr) cout<<"null"<<endl;
    else cout<<"not null"<<endl;
    
  	
  	
  	
  	
  	
  
    return 0;
}