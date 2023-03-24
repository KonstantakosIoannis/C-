# include <iostream>

using namespace std;

int main () {
	
	float x ;
	
	cout<<"give me a number : ";
	cin>>x;
	
	try {         //  αυτο το κανουμε για να αποφυγουμε μια μαλακια του χρηστη συνηθως. πχ να βαλει διαρετη 0
	 if (x !=0){	// αν δεν βαλει κανουμε κανονικα οτι ειναι να κανουμε.
	 	cout<<float(2/x)<<endl;     
	 }
	 else throw (x);    //αν βαλει κανουμε throw την exception
	}
	
	
	catch (float x)
	{    // Και μετα ΠΑΝΤΑ την κανουμε catch. 
		cout<<x<<" is not valid"<<endl;   // δηλαδη τι κανουμε σε περιπτωση που μας παρουσιαστει αυτη η εξαιρεση
	}
	
	
	
	return 0;
}
