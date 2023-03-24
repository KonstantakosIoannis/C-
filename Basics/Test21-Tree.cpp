#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class ball
{
	private :
		ball * left;
		ball * right;
		int price;
	
	public :
		ball(int price)
		{
			cout<<"Fillo"<<endl;
			right=NULL;
			left=NULL;
			this->price=price;
		}
		
		ball(int price , ball * left , ball * right)
		{
			cout<<"Kladi"<<endl;
			this->left=left;
			this->right=right;
			this->price=price;
		}
		
		//anadromikh
		/*
		void print()
		{
			cout<<"Data : "<<this->price<<endl;
			if(this->left)this->left->print();
			if(this->right)this->right->print();
		}
		*/
		
		
		
		//stack- STOIBA - LIFO
		/*
		void print()
		{
			stack<ball*> remaining;
			
			remaining.push(this);
			
			while(!remaining.empty())
			{
				ball * current = remaining.top();// bazw sti metabliti remainig to top tis stoibas
				remaining.pop(); //  to bgazw apo ti stoiba
				
				cout<<current->price<<endl;
				if(current->right)remaining.push(current->right); // an exei deksi paidi to bazw sti stoiba
				if(current->left)remaining.push(current->left); // omoiws gia aristero pedi
				
				// kai twra tsekarw to teleutaio stoixeio pou exw kanei push			
			}
		}
		*/
		
		
		
		// queue - FIFO - OYRA
		/*
		void print()
		{
			queue <ball *> remaining;
			remaining.push(this);
			
			while(!remaining.empty())
			{
				ball * current = remaining.front();
				remaining.pop();
				cout<<current->price<<endl;
				if(current->left)remaining.push(current->left);
				if(current->right)remaining.push(current->right);
				//1-2-3-4-5-6-7
			}
			
			
		}
		
		*/
};


int main()
{
	ball b7(7);
	ball b6(6);
	ball b5(5);
	ball b4(4);
	ball b2(2,&b4,&b5);
	ball b3(3,&b6,&b7);
	ball b1(1,&b2,&b3);	
	
	//b1.print();
	
	//Ηomework - Na ginei templated\
	
	
	return 0;
}
