/*
customised vector
make the following lines of code run properly 
SOLUTION : myVec
*/

//////////////////////////////  TEST  1  //////////////////////////

int main()
{
	cout<<"Test 1 : "<<endl<<endl;
	
	vec <int> y(5); //vector with 5 elements
	
	
	y.push_back(20); //push back  
	y.push_back(30);
	y.push_back(40);
	y.push_back(50);
	y.push_back(60);
	y.push_back(70);
	y.push_back(80);
	
	
	
	y.pushFront(10); // push front 
	
	y.popBack(); // delete last cell
	
	y.popFront();//delete first cell (array[0])
	
	y.push_at(90,4); // insert 90 in the fourth position
	
	y.pop_at(2); // delete cell 2 
	
	vec <int> y2(2);
	y2.push_back(200);
	y2.push_back(300);
	
	y=y+y2; // operator +
	
	vec <int> y3= y2; // copy constructor
	y3=y;  // operator =
	
	
	y.taks(); // sort ASC or DESC your choice
	
	y.flip(); // flip the vector
	
	y.print(); // print the whole vector
	
//////////////////////////////  TEST  2  //////////////////////////

	cout<<endl<<"Test 2 :"<<endl<<endl;
	
	if(y.empty())cout<<"I am empty "<<endl;  // no comments :D
	else
	{
		cout<<"My size is : "<<y.mySize()<<" bytes"<<endl;  //vector size in bytes
	
		cout<<"I have "<<y.howLong()<<" elements"<<endl;  //count the cells
		
		cout<<"My first element is : "<<y.begin() //array[0]
		<<" and my last one is : "<<y.end()<<endl; // array[last]
	}
	
	cout<<"Do you have a '30' in your elements ?          ";
	if(y.find(30))cout<<"Yes i Do!!"<<endl;  // 
	else cout<<"Sorry but NO"<<endl;
	
	cout<<"My third element is : "<<y[2]<<endl;  // returns array[i]
	
	y.erase();                      // clear the vector (DONT DELETE)
	if(y.empty())cout<<"I am empty "<<endl;
	y.off();                       // DELETE
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