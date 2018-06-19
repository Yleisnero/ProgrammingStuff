#include <iostream>
#include <string>

enum struct Gattung {Gliedertier = 1, Vogel, Saeugetier, Weichtier, Fisch, Kriechtier, Spinne};

class tier{

protected: std::string name;
	   int anzahlBeine;
	   Gattung gattung;

public: tier(std::string nameN, Gattung gattungN, int anzahlBeineN = 4) : name(nameN), gattung(gattungN), anzahlBeine(anzahlBeineN){ }
	
	virtual void beschreibungAusgeben(){
		std::cout << "Ich heiße " << name << " und habe " << anzahlBeine << " Beine"
		<< std::endl;
	}

	virtual void paarung(tier t){
		if(gattung == t.gattung){
			std::cout << "Erfolgreiche Paarung von " << name << " und " << t.name << std::endl; 		
		}else{
			std::cout << "Keine erfolgreiche Paarung! " << std::endl; 
		}
	}
};

class insekt : public tier{

private: int anzahlFluegel;

public: insekt(std::string nameN, Gattung gattungN, int anzahlFluegelN, int anzahlBeineN = 4) : tier(nameN, gattungN, anzahlBeineN), anzahlFluegel(anzahlFluegelN){ }
	
	bool kannFliegen(){
		if(anzahlFluegel > 1){
			return true;
		}else{
			return false;
		}
	}

	void beschreibungAusgeben(){
		std::cout << "Ich heiße " << name << " und habe " << anzahlBeine << " Beine "
		<< "und habe " << anzahlFluegel << " Fluegel" << std::endl;
	}

	void paarung(tier t){
		if(gattung == t.gattung){
			if(gattung == Gattung::Spinne){
				std::cout << "Erfolgreiche Paarung von " << name << " und " << t.name << std::endl;
				std::cout << name << " frisst " << t.name << std::endl;
}else{
			std::cout << "Erfolgreiche Paarung von " << name << " und " << t.name << std::endl;
} 		
		}else{
			std::cout << "Keine erfolgreiche Paarung! " << std::endl; 
		}
	}

};


int main(){
	tier t1("Eumel", Gattung::Weichtier, 42);
	t1.beschreibungAusgeben();

	tier t2("Hundi", Gattung::Weichtier);
	t2.beschreibungAusgeben();

	
	insekt i1("spiderschwein", Gattung::Spinne, 0, 8);
	i1.beschreibungAusgeben();

	insekt i2("spinneee", Gattung::Spinne, 0, 7);
	i1.paarung(i2);

	if(i1.kannFliegen()){
		std::cout << "Ich kann fliegen!!!" << std::endl;
	}else{
		std::cout << "Ich kann nicht fliegen :(" << std::endl;
	}

	t1.paarung(t2);

return 0;
}
