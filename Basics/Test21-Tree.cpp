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
		
		
		/*
		void print()
		{
			cout<<"Data : "<<this->price<<endl;
			if(this->left)this->left->print();
			if(this->right)this->right->print();
		}
		*/
		
		
		
		//stack - LIFO
		/*
		void print()
		{
			stack<ball*> remaining;
			
			remaining.push(this);
			
			while(!remaining.empty())
			{
				ball * current = remaining.top();
				remaining.pop(); 
				
				cout<<current->price<<endl;
				if(current->right)remaining.push(current->right); 
				if(current->left)remaining.push(current->left); 
				
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
	
	//Ηomework - template
	
	
	return 0;
}
