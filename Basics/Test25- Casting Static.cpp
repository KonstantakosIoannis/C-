#include <iostream>

using namespace std;

class animal{};

class dog:public animal{};


int main()
{
	int x=10;
	double y = 10.5;
	
	int x2=(int)y;
	int x3=y;// tetoiou tipou casts ginontai automata stin c++
	
	cout<<x<<endl<<y<<endl<<x2<<endl<<x3<<endl;
		
	///////////////////////////// class casting
	
	class animal a1;
	class dog d1;
	
	animal a2 = d1; // auto to cast einai ok. trexei automata kai einai idio me to katw
	animal a3 = (animal)d1;// idio me to panw
	
	//dog d2=(dog)a1; ERROR den mporw na eksidikeusw ena animal kai na to kanw dog cast
	//auto pou mporw na kanw omws einai to ekshs
	
	dog * dPtr = (dog*)&a1;
	//SOS nai men ginetai OMWS einai oti xeirotero mporw na kanw
	// tha dhmiourghthoun apeira logika sfalmata run time
	
	// an thelw nte kai kala na kanw tin parapanw metatropi alla de thelw na doulepsw me pointers
	
	dog dd2 = * static_cast <dog*> (&a1);
	
	/*
	to dog mporei na gine animal (grammes 25-26) xoris na xoume opoiodipote thema
	
	genika otan kanw cast pros ta panw(apo progono se apogono) den ginetai na mou parousiastoun sfalmata
	giati sigoura o progonos exei oti exei o apogonos(pedia sinartisis ktl)
	
	to antitheto omws den isxiei .  for example to dog tha mporouse na exei ena pedio i kapoia function
	pou dn tin exei o apogonos kai gi auto to casting apo apogono se progono APAGOREUETAI dia ropalou
	
	an parola auta gia kapoio poli sigkekrimeno kai spanio logo prepei na ginei tote kanoume static cast
	to opoio mas epitrepei na parakampsoume oles tis parapanw apagoreuseis (compilie time OMWS)
	se run time an apo lathos mou kalesw sto dd2 kapoia methodo tou dog tote tha xoume sobara problimata
	
	ARA static cast kanw mono AN :
	1) einai apolitws aparaithto logw idiomorfias tou programmatos kai den ginetai alliws
	2) an exw eksasfalisei oti den tha treksei pote to sigkekrimeno antikeimeno pou kanw cast 
	kapoia methodo tou apogonou i de tha xreiastw kapoio pedio tou etc etc
	3) stin praksi den ginetai sxedon pote - iparxei apla san dinatotia apo ti c++
	4) de tha zitithei pote stin eksetasi (eite grapti eite se pc) na kaneis static cast
	einai apla theoria . mporei na pesei eite ws erotisi theorias anaptiksis , eite ws ena px
	pou tha sou leei ti mporei na kanei i ti den mporei na kanei to antikeimeno pou exoume kanei
	static cast. i apantisi kai stis dio periptwseis einai i parapanw theoria
	*/	
	return 0;
}