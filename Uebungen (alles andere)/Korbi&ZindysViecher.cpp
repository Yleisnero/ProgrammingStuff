#include <iostream>
using namespace std;

class tier {
	protected:
		string name;
		int anzahlBeine;
		int gattung;
		
	public:
		tier(string name, string gattung, int anzahlBeine = 4) : name(name), 
		anzahlBeine(anzahlBeine){
			if (gattung=="Gliedertier")
				this->gattung = 1;
			else if (gattung=="Vogel")
				this->gattung = 2;
			else if (gattung=="Säugetier")
				this->gattung = 3;
			else if (gattung=="Weichtier")
				this->gattung = 4;
			else if (gattung=="Fisch")
				this->gattung = 5;
			else if (gattung=="Kriechtier")
				this->gattung = 6;
		}
		
		void beschreibungAusgeben(){
			cout << "Name: " << name << endl;
			switch(gattung){
				case 1:
					cout << "Gattung: Gliedertier" << endl;
					break;
				case 2:
					cout << "Gattung: Vogel" << endl;
					break;
				case 3:
					cout << "Gattung: Säugetier" << endl;
					break;
				case 4:
					cout << "Gattung: Weichtier" << endl;
					break;
				case 5:
					cout << "Gattung: Fisch" << endl;
					break;
				case 6:
					cout << "Gattung: Kriechtier" << endl;
					break;
				default:
					cerr << "Fehler mit int gattung" << endl;
					break;
			}
			cout << "Beine: " << anzahlBeine << "\n" << endl;
			
		}
		
		void paarung(tier &b){
			if (this->gattung == b.gattung)
				cout << "Paarung geglückt!" << endl;
			else 
				cout << "Bitte keine Inzucht!" << endl;
		}
		
		string getName(){return name;}
};

class insekt : public tier {
	private:
	using tier::tier;
		int fluegel;
	public:
	
		insekt(string name, string gattung, int beine, int fluegel) : tier(name, gattung, beine), fluegel(fluegel){}
		
		bool kannFliegen(){
			return fluegel > 1;
		}
		
		virtual void beschreibungAusgeben(){
			if (kannFliegen())
				cout << name << " kann Fliegen!" << endl;
			else 
				cout << name << " kann nicht Fliegen!" << endl;
		}
		
};

int main(){
	tier daisy("Daisy", "Säugetier", 4);
	tier joey("Joey", "Säugetier");
	tier hund("Cujo", "Säugetier");
	tier fisch("Nemo", "Fisch", 0);
	insekt test("testersekt", "Gliedertier", 6, 2);
	
	daisy.beschreibungAusgeben();
	joey.beschreibungAusgeben();
	fisch.beschreibungAusgeben();
	hund.beschreibungAusgeben();
	test.beschreibungAusgeben();
	
	daisy.paarung(hund);
	
	return 0;
}
