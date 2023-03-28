#include <iostream>

using namespace std;

template <typename T>
class vec
{	
	private :
		unsigned int data;
		T * pinakas;  
		int position;
		
	public :
		////////constructors////////
		vec(int data)
		{
			this->data=data;
			pinakas = new T [data];
			position=0;
		}
		
		vec(const vec & src)
		{
			cout<<"Copy con"<<endl;
			this->data=src.data;
			this->position=src.position;
			this->pinakas=new T [data];
			for (int i=0; i<data; i++)this->pinakas[i]=src.pinakas[i];
		}
		
		vec & operator = (const vec & src)
		{
			cout<<"Operator ="<<endl;
			if(this==&src)return *this;
			this->data=src.data;
			this->position=src.position;
			if(this->pinakas)
			{
				delete [] pinakas;
			}
			this->pinakas=new T [data];
			for (int i=0; i<data; i++)this->pinakas[i]=src.pinakas[i];
			return *this;	
		}
	
		///////functions///////
		void push_back(T x)
		{
			if(position<data)
			{
				pinakas[position]=x;
				position++;
			}
			else
			{
				T temp[data];
				for(int i=0; i<data; i++)temp[i]=pinakas[i];
				delete [] pinakas;
				data++;
				pinakas = new T [data];
				for(int i=0; i<data; i++)pinakas[i]=temp[i];
				pinakas[position]=x;
				position++;	
			}
		}
		
		void pushFront(T x)
		{
	
				T temp[data];
				for(int i=0; i<data; i++)temp[i]=pinakas[i];
				delete [] pinakas;
				data++;
				pinakas = new T [data];
				pinakas[0]=x;
				for(int i=1; i<data; i++)pinakas[i]=temp[i-1];
				position++;		
		}
		
		void push_at(T x , int pos)
		{
		T temp[data];
		for(int i=0; i<data; i++)temp[i]=this->pinakas[i];
		data++;
		position++;
		delete [] pinakas;
		this->pinakas=new T[data];
		for(int i=0; i<pos; i++)this->pinakas[i]=temp[i];
		pinakas[pos]=x;
		for(int i=pos+1; i<data; i++)this->pinakas[i]=temp[i-1];	
		}
		
		
		void popBack()
		{
		this->position=this->position-1;
		T temp[this->position];
		for(int i=0; i<position; i++)temp[i]=pinakas[i];
		delete [] pinakas;
		pinakas=new T[position];
		for(int i=0; i<position; i++)pinakas[i]=temp[i];
		data--;
		}
		
		
		void popFront()
		{
		this->position=this->position-1;
		T temp[this->position];
		for(int i=0; i<position; i++)temp[i]=pinakas[i+1];
		delete [] pinakas;
		pinakas=new T[position];
		for(int i=0; i<position; i++)pinakas[i]=temp[i];
		data--;
		}
		
		void pop_at(unsigned int pos)
		{
		T temp[data-1];
		data--;
		position--;
		for(int i=0; i<pos; i++)temp[i]=this->pinakas[i];
		for(int i=pos; i<data; i++)temp[i]=this->pinakas[i+1];
		delete [] pinakas;
		pinakas=new T[data];
		for(int i=0; i<data; i++)this->pinakas[i]=temp[i];
		}
		
		vec operator+(const vec & right)
		{
			T temp[data];
			for(int i=0; i<this->position; i++)temp[i]=this->pinakas[i];
			delete [] pinakas;
			pinakas = new T [data+right.data];
			for(int i=0; i<this->position; i++)this->pinakas[i]=temp[i];
			
			for(int i=this->position; i<this->position+right.position; i++)this->pinakas[i]=right.pinakas[i-this->position];
			this->data=this->data+right.data;
			this->position=this->position+right.position;
			return *this;
		}
		
		void flip()
		{
			T temp[position];
			for(int i=0; i<position; i++)temp[i]=pinakas[i];
			for(int i=0; i<position; i++)pinakas[i]=temp[position-i-1];
		}
		
		void taks()// auti mporei na ginei kai private kai na kaleitai esoterika
		{
			for(int i=0; i<data; i++)
			{
				for(int j=i+1; j<data; j++)
				{
					if(pinakas[i]>pinakas[j])   //d1>d2
					{
						T temp=pinakas[i];
						pinakas[i]=pinakas[j];
						pinakas[j]=temp;
		}}}}
		
		/////////////////////functions Test 2
		size_t mySize()
		{
			size_t sum=0;
			for (int i=0; i<position; i++)sum=sum+sizeof(pinakas[i]);
			return sum;	
		}
		
		unsigned int howLong()
		{
			return position;
		}
		
		bool empty()
		{
			if (data==1&&position==0)return true;
			return false;
		}
		
		T end()
		{
			return pinakas[position-1];
		}
		
		T begin()
		{
			return pinakas[0];
		}
		
		bool find(T x)
		{
			for(int i=0; i<position; i++)
			{
				if(x==pinakas[i])return true;
			}
			return false;
		}
		
		
		T operator[](unsigned x)
		{
			return pinakas[x];
		}
		
		void off()
		{
			delete [] pinakas;
			pinakas=NULL;
			position=0;
			data=0;
		}
		
		void erase()
		{
			delete [] pinakas;
			pinakas = new T[1];
			data=1;
			position=0;	
		}
		
		///////////////////////////////////////
		void print()
		{
			for (int i=0; i<data; i++)cout<<pinakas[i]<<endl;
			//for (int i=0; i<position; i++)cout<<pinakas[i]<<endl;
		}
		
		

};


////////////////////////////////////////////////
class dog
{
	private :
		int weight;
	
	public :
		dog(){this->weight=0;}
		dog(int weight){this->weight=weight;}
		
		bool operator>(const dog & right)
		{
			if(this->weight>right.weight)return true;
			return false;
		}
		
		friend ostream & operator<<(ostream & os , dog & right)
		{
			os<<right.weight;
			return os;
		}	
};
//////////////////////////////  TEST  1  //////////////////////////

int main()
{
	cout<<"Test 1 : "<<endl<<endl;
	
	vec <int> y(5); // custom "vector" with 5 cells
	
	
	y.push_back(20); //push back 
	y.push_back(30);
	y.push_back(40);
	y.push_back(50);
	y.push_back(60);
	y.push_back(70);
	y.push_back(80);
	
	
	
	y.pushFront(10); // push front 
	
	y.popBack(); // delete last
	
	y.popFront();//delete first (array[0])
	
	y.push_at(90,4); // insert 90 at position N.4	
	y.pop_at(2); // delete cell N.20
	
	vec <int> y2(2);
	y2.push_back(200);
	y2.push_back(300);
	
	y=y+y2; // operator +
	
	vec <int> y3= y2; // copy constructor
	y3=y;  // operator =
	
	
	y.taks(); // sort Desc
	
	y.flip(); 
	
	y.print(); 
//////////////////////////////  TEST  2  //////////////////////////

	cout<<endl<<"Test 2 :"<<endl<<endl;
	
	if(y.empty())cout<<"I am empty "<<endl;  
	else
	{
		cout<<"My size is : "<<y.mySize()<<" bytes"<<endl;  //vector size(bytes)
	
		cout<<"I have "<<y.howLong()<<" elements"<<endl;  //number of elements
		
		cout<<"My first element is : "<<y.begin() //array[0]
		<<" and my last one is : "<<y.end()<<endl; // array[last]
	}
	
	cout<<"Do you have a '30' in your elements ?          ";
	if(y.find(30))cout<<"Yes i Do!!"<<endl;  
	else cout<<"Sorry but NO"<<endl;
	
	cout<<"My third element is : "<<y[2]<<endl;  
	
	y.erase();                      
	if(y.empty())cout<<"I am empty "<<endl;
	y.off();                       //delete 
	if(y.empty())cout<<"I am empty "<<endl;  
	
//////////////////////////////  TEST  3  //////////////////////////

	cout<<endl<<"Test 2 :"<<endl<<endl;
	
	vec<dog> d(5);
	
	dog d1;
	dog d2(5);
	dog d3;
	dog d4(55);
	dog d5(12);
	dog d6(58);
	dog d7(4844);
	dog d8(525);
	
	d.push_back(d1);
	d.push_back(d2);
	d.push_back(d3);
	d.push_back(d4);
	d.push_back(d5);
	d.push_back(d6);
	d.push_back(d7);
	d.push_back(d8);
	
	
	d.print();
	
	d.taks();
	
	cout<<endl;
	d.print();
	
	return 0;
}
