# include <iostream>
# include <fstream>
# include <string>

using namespace std;

int main () {
	
	string leksi = "gia sou ";
	
	ofstream writer("stevequote.txt");   // δημιουργουμε το steve quate txt το οποιο μπαινει στη μεταβλητη  writer
	
	if(!writer) {    // τσεκαρουμε αν υπαρχει το αρχειο
		cout<<"error opening file"<<endl;    
		return -1;
	}
	else {
		writer<<leksi<<endl;   // προσθετουμε στο αρχειο τη string leksi
		writer.close();        // και το κλεινουμε
		
	}
	
	ofstream writer2 ("stevequote.txt" , ios::app);  //  ανοιγουμε εναν νεο ofstream ωστε να γραψουμε στο τελς του stevequate 
													// αυτο το πετυχαινουμε με το ios::append!
						
	//  ξανακανουμε τον ιδιο ελεγχο : 
	
	if (!writer2){
		cout<<"error";
		return -1;
	}
	else {
		writer2<<"\n - John"<<endl;  // αλλαοζουμε γραμμη με το \n και προσθετουμε και προσθετουμε κι αλλλα γραμματα (john)
		writer2.close();             // κλεινουμε το writer
	}
					
	char letter ;
	
	ifstream reader("stevequote.txt"); // φτιαχνουμε ενα ifstream το οποιο ονομαζουμε reader  ωστε να διαβασουμε το αρχείο
	
	// παλι ελεγχος οπως πριν: 
	
	if (!reader){
		cout<<"error"<<endl;
		return -1;
	}
	else {   // και ετσι εκτυπωνουμε ενα txt
		for (int i=0;   !reader.eof(); i++) // !reader end of file οσο δηλαδή δεν είμαστε στο τελος του αρχείου
		reader.get(letter);  // παιρνουμε απο το reader ενα char και το βαζουμε στο letter
		cout<<letter;
	}
	cout<<endl;
	reader.close();   // για καποιο λογο ο παραπανω τροπος δεν εκτυπωνει τιποτα οποτε κανουμε το επομενο : 
	
	
	ifstream file("stevequote.txt");
	cout<<file.rdbuf();
	file.close();
	
	
return 0;
}
