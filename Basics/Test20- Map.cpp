#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string,int> data;
	// exw san dedomena ints
	// kai exw san kleidia strings
	
	
	//1os tropos eisagwgis dedomenwn me th xrhsh tis sillogis pair
	data.insert(pair<string,int>("John",30));
	
	//1os tropos kai pali alla me dio grammes
	pair<string ,int> Tom ("Tom",15);
	data.insert(Tom);
	
	//pair<string,int> ("Lila",5); ginetai kai auto. na dilwsw pair xoris onoma
	
	//2os tropos eisagwgis
	data["jim"]=11; // psaxnei to kouti me to onoma jim. an den iparxei tote dimiourgei
	// ena neo kouti kai tou dinei tin timh 11
	
	data["jim"]=12;// tora pou iprarxei paei kai tou allazei tin timh
	
	
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
	//SOS to .end() paei na pei oti pleon exei bgei ektos map
	
	
	map<string,int>::iterator result3 = data.find("liza");
	if(result3!=data.end())cout<<result3->first<<"   "<<result3->second<<endl;
	
	result3 = data.find("lizaTTTTTTT");
	if(result3!=data.end())cout<<result3->first<<"   "<<result3->second<<endl;
	else cout<<"NOT FOUND"<<endl;
	
	
	
	//1os tropos diasxisis enos map
	for(map<string,int>::iterator i=data.begin(); i!=data.end(); ++i)
	{
		cout<<i->first<<endl;
		
	}// prosekse ti seira taksinomisis
	
	cout<<endl<<endl;
	
	//2os tropos
	for(auto item:data)
	{
		cout<<item.first<<endl;
		cout<<item.second<<endl;
	}
	
	return 0;
}