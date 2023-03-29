#include <iostream>

using namespace std;
  

class animal
{
	public :
    	virtual void print(){cout << "animal" << endl;} //check without tve virtual
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

  	
  	
  	
  	cat * cPTR = dynamic_cast<cat*>(&d1);
  	//c++ gives us a warning when casting didn't complete
	
	if(cPTR==nullptr) cout<<"null"<<endl;
    else cout<<"not null"<<endl;
   	
   	
   	
   	
   	
   	dog * dPTR = dynamic_cast<dog*>(&a1);
  	if(dPTR==nullptr) cout<<"null"<<endl;
    else cout<<"not null"<<endl;
    
  	
  	
  	
  	
  	
  
    return 0;
}
