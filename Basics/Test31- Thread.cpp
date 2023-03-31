#include <iostream>
#include <thread>

using namespace std;

void go(int x , int y)
{
	int z=0;
	for(int i=0; i<50000; i++)z=z+1;
	cout<<z+x+y<<endl;
	
}

int main()
{
	//thread myThread = thread(go,100,50);
	//myThread.join();
	
	
	
	
	
	
	int num =8;
	thread * pin = new thread[num];
	for(int i=0; i<num; i++) 
	{
		pin[i]=thread(go,i+10,50);	
	}
	for(int i=0; i<num; i++) pin[i].join();
	
	//for(int i=0; i<8; i++)go(i+10,50);
	
	
	return 0;
}
