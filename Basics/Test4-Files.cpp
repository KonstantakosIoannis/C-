# include <iostream>
# include <fstream>
# include <string>

using namespace std;

int main () {
	
	string leksi = "hello";
	
	ofstream writer("stevequote.txt");   
	
	if(!writer) {    
		cout<<"error opening file"<<endl;    
		return -1;
	}
	else {
		writer<<leksi<<endl;   //adding one more word
		writer.close();       
		
	}
	
	ofstream writer2 ("stevequote.txt" , ios::app);  
						
	
	
	if (!writer2){
		cout<<"error";
		return -1;
	}
	else {
		writer2<<"\n - John"<<endl;  // change line and add one more word('john')
		writer2.close();             
	}
					
	char letter ;
	
	ifstream reader("stevequote.txt"); 
	
	
	
	if (!reader){
		cout<<"error"<<endl;
		return -1;
	}
	else {   //print
		for (int i=0;   !reader.eof(); i++) //end of file
		reader.get(letter);  
		cout<<letter;
	}
	cout<<endl;
	reader.close(); 
	
	
	ifstream file("stevequote.txt");
	cout<<file.rdbuf();
	file.close();
	
	
return 0;
}
