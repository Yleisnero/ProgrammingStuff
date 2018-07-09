#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

enum struct Gattung {Gliedertier = 1, Vogel, Saeugetier, Weichtier, Fisch, Kriechtier, Spinne};

class zootier{
	public:
	virtual void fuettern() = 0;
	zootier(std::string n, int anzB) : name(n), anzahlBeine(anzB){};
	
	public:
	std::string name;
	int anzahlBeine;

};

class tier: public zootier{
	
	public:
	Gattung gattung;

	public: tier(std::string nameN, Gattung gattungN, int anzahlBeineN = 4) : zootier(nameN, anzahlBeine), gattung(gattungN){ }
	
		virtual void beschreibungAusgeben(){
			std::cout << "Ich heiße " << name << " und habe " << anzahlBeine << " Beine"
			<< std::endl;
		}

		friend std::ostream &operator << (std::ostream &outStream, tier &t);

		virtual void paarung(tier &t){
			if(gattung == t.gattung){
				std::cout << "Erfolgreiche Paarung von " << name << " und " << t.name << std::endl; 		
			}else{
				std::cout << "Keine erfolgreiche Paarung! " << std::endl; 
			}
		}

	virtual void fuettern(){
		std::cout << "Ich bin irgend ein Tier und esse irgendwas!" << std::endl;	
	}
};

std::ostream &operator << (std::ostream &outStream, tier &t){
			outStream << "Ich heiße " << t.name << " und habe " << t.anzahlBeine << " Beine"<< std::endl;
			return outStream;
		}

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

void fuettern(){
		std::cout << "Ich bin irgend ein Insekt und esse luft lol" << std::endl;	
	}

	void beschreibungAusgeben(){
		std::cout << "Ich heiße " << name << " und habe " << anzahlBeine << " Beine "
		<< "und habe " << anzahlFluegel << " Fluegel" << std::endl;
	}

	void paarung(tier &t){
		if(gattung == t.gattung){
			if(gattung == Gattung::Spinne){
				std::cout << "Erfolgreiche Paarung von " << name << " und " << t.name << std::endl;
				std::cout << name << " frisst " << t.name << std::endl;
				//t.~tier();
}else{
			std::cout << "Erfolgreiche Paarung von " << name << " und " << t.name << std::endl;
} 		
		}else{
			std::cout << "Keine erfolgreiche Paarung! " << std::endl; 
		}
	}

};

class loewe : public tier{
	public:
	loewe(std::string n, Gattung g, int anzB) : tier(n, g, anzB){}
	void fuettern(){
		std::cout << "Ich bin ein Löwe, lecker rohes Fleisch mmmmh mmmh ham ham lecker!!" << std::endl;	
	}
};

class tierpfleger{
	public:
	void fuettern(zootier &t){
		std::cout << "Ich füttere ..." << std::endl;
		t.fuettern();
	}	
};


int main(){
	tier t1("Eumel", Gattung::Weichtier, 42);
	std::cout << t1;

	tier t2("Hundi", Gattung::Weichtier);
	t2.beschreibungAusgeben();

	
	insekt i1("spiderschwein", Gattung::Spinne, 0, 8);
	i1.beschreibungAusgeben();

	insekt i2("spinneee", Gattung::Spinne, 0, 7);
	i2.beschreibungAusgeben();
	i1.paarung(i2);

	if(i1.kannFliegen()){
		std::cout << "Ich kann fliegen!!!" << std::endl;
	}else{
		std::cout << "Ich kann nicht fliegen :(" << std::endl;
	}

	t1.paarung(t2);
	
	loewe lo1("löwi", Gattung::Weichtier, 4);
	tierpfleger tp1;

	std::vector<std::reference_wrapper<tier>> zoo; //using std::reference_wrapper -> right output 
	zoo.push_back(t1);
	zoo.push_back(i1);
	zoo.push_back(lo1);

	std::for_each(zoo.begin(), zoo.end(), [&tp1](tier &t/*each tier
	has to be called by reference*/ ){ tp1.fuettern(t); });
	

return 0;
}
