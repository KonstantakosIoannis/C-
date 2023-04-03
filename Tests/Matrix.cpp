#include <iostream>


namespace math
{
	class matrix
	{
		private :
			unsigned int width;
			unsigned int height;
			int * buffer;// = new int[width*height];   
			
	
			
		public : 
			matrix()
			{
				this->width=0;
				this->height=0;
				buffer=nullptr;
			
			}
			
			matrix(unsigned int width , unsigned int height)
			{
				this->height=height;
				this->width=width;
			
				
				if(width==0||height==0)
				{
					std::cout<<"Error wrong dimensions"<<std::endl;
					buffer=nullptr;
					return ;
				}
				
				buffer= new int[width*height];  
				
				//for(int i=0; i<width*height; i++)std::cout<<buffer[i]<<std::endl;
				
				for(int i=0; i<width*height; i++)
				{
					buffer[i]=2;
				}
				
				
				//int * buffer = new int [10];
			}
			
			//m_.print();
			
			void print()
			{
				for(int i=0; i<height*width; i++)
				{
					std::cout<<buffer[i]<<std::endl;
				}
				
			}
			
			
			~matrix()
			{
				if(buffer!=nullptr)
				{
					delete [] buffer;
					buffer=nullptr;
				}
			}
			
			bool operator ==(matrix & right)
			{
				if(this->width==right.width && this->height==right.height)
				{
					//return true;
					for(int i=0; i<this->width*this->height; i++)
					{
						if(this->buffer[i]!=right.buffer[i]) return false;
					}
					
					return true;
				}
				else
				{
					return false;
				}
			}
			
			
			int & operator ()(unsigned int a , unsigned int b)
			{
				if(a<width && b<height) return buffer[8];
				else
				{
					std::cout<<" out of bounds "<<std::endl;
					return buffer[0];
				 } 
			}	
			
			matrix operator+(matrix & right)
			{
				
				
				if(this->width==right.width && this->height==right.height)
				{
					matrix temp(width,height);
					for(int i=0; i<width*height; i++)
					{
						temp.buffer[i]=this->buffer[i]+right.buffer[i];
					}	
					return temp;
				}
				else return matrix();
				
			}	
			
			
			friend int operator +(int alpha , matrix & right)
			{
				int sum=0;
			
				for(int i=0; i<right.height*right.width; i++ )
				{
					sum=sum+right.buffer[i];
				}
				return sum+5;
			}
			
			friend void operator *(int x , matrix & right)
			{
				for(int i=0; i<right.height*right.width; i++ )
				{
					right.buffer[i]=right.buffer[i]*5;
				}
			}
			
			friend std::ostream & operator<<(std::ostream& os, matrix & right)
			{
				std::cout<<right.buffer[0];
				//return os; 
				return std::cout;
			}
			
			//unsigned int operator ()()
			operator   unsigned int ()
			{
				return width*height;
			}
			
			void operator()()
			{
				std::cout<<std::endl;
				std::cout<<std::endl<<height*width<<"....."<<std::endl;
			}
			
			void operator()(std::string x)
			{
				
			}
			
			std::string operator()(int a , int b ,int c)
			{
				return "hello";
			}
	};
	
	
	
}



int main()
{
	
	
	//std::cout<<"Hello";
	
	math::matrix m;
	
	
	
	unsigned int x=256;
	unsigned int y=256;
	
	math::matrix m_ (x,y);  //constructor
	math::matrix m3 (x,y);
	
	
	
	math::matrix * m__ = new math::matrix(2,2);
	
	
	m_.print();   
	
	bool theSame = (m==m_);   //m.operator ==(m_)
	//std::cout<<theSame;
	
	int xyx = m_(5,5);  // m_.operator[5,5]
	
	m_(5,5)=4;
	
	
	math::matrix mX = m_+m3;
	
	int alpha = 5+m3;  
	
	5*m3;
	//m3.print();
	
	std::cout<<m3<<std::endl;
	 
	std::string name="Rex";
	
	unsigned int megethos = (m3);  //operator ()     casting operator
	std::cout<<megethos;
	
	m();  //cout<<size
	delete m__;
	
	
	return 0;
}