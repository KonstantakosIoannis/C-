#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string,int> data;
	// ints values - string keys
	
	//Insert with pair
	data.insert(pair<string,int>("John",30));
	
	//the same
	pair<string ,int> Tom ("Tom",15);
	data.insert(Tom);
	
	//pair<string,int> ("Lila",5); //same
	
	//another more efficient way of inserting data
	data["jim"]=11 // if 'jim' doesnt exist , create a new one 
	
	data["jim"]=12;// if exists it changes the value
	
	
	data["liza"]=15;
	data["roulis"]=7;
	data["stamatis"]=22;
	
	/////iterators
	
	
	map<string,int>::iterator result;
	
	result = data.begin();
	
	
	
	//cout<<result<<endl; ERRORS
	//cout<<result2<<endl;
	//cout<<*result<<endl;
	//cout<<&result2<<endl;
	
	cout<<result->first<<"   "<<result->second<<endl;
	
	
	
	//map<string,int>::iterator result2 = data.end();
	//cout<<result2->first<<"   "<<result2->second<<endl;
	
	
	
	map<string,int>::iterator result3 = data.find("liza");
	if(result3!=data.end())cout<<result3->first<<"   "<<result3->second<<endl;
	
	result3 = data.find("lizaTTTTTTT");
	if(result3!=data.end())cout<<result3->first<<"   "<<result3->second<<endl;
	else cout<<"NOT FOUND"<<endl;
	
	
	
	//1
	for(map<string,int>::iterator i=data.begin(); i!=data.end(); ++i)
	{
		cout<<i->first<<endl;
		
	}
	
	cout<<endl<<endl;
	
	//2
	for(auto item:data)
	{
		cout<<item.first<<endl;
		cout<<item.second<<endl;
	}
	
	return 0;
}
