#include <iostream>
#include <string>

class tier{

protected: std::string name;
	   int anzahlBeine;

public: tier(std::string nameN, int anzahlBeineN = 4) : name(nameN), anzahlBeine(anzahlBeineN){ }
	
	void beschreibungAusgeben(){
		std::cout << "Ich heiße " << name << " und habe " << anzahlBeine << " Beine"
		<< std::endl;
	}
};

class insekt : public tier{

private: int anzahlFluegel;

public: insekt(std::string nameN, int anzahlFluegelN, int anzahlBeineN = 4) : tier(nameN, anzahlBeineN), 		 			anzahlFluegel(anzahlFluegelN){ }
	
	bool kannFliegen(){
		if(anzahlFluegel > 1){
			return true;
		}else{
			return false;
		}
	}

	virtual void beschreibungAusgeben(){
		std::cout << "Ich heiße " << name << " und habe " << anzahlBeine << " Beine "
		<< "und habe " << anzahlFluegel << " Fluegel" << std::endl;
	}

};


int main(){
	tier t1("Eumel", 42);
	t1.beschreibungAusgeben();

	tier t2("Hundi");
	t2.beschreibungAusgeben();

	insekt i1("spiderschwein", 0, 8);
	i1.beschreibungAusgeben();

	if(i1.kannFliegen()){
		std::cout << "kann fliegen!!!" << std::endl;
	}else{
		std::cout << "kann nicht fliegen :(" << std::endl;
	}

return 0;
}
