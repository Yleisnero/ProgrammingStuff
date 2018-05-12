#include "std_lib_facilities.h"


enum struct foarb{oichl = 1, gros = 2, herz = 3, schelln = 4};
enum struct schlog{siebener = 7, achter = 8, neiner = 9, zehner = 10, unter = 11, ober = 12, kine = 14, sau = 13 };

struct koartn {
	foarb f;
	schlog s;

	//Methode zum Ausgeben einer (der aktuellen) Karte
	void print(){ 

		switch(f){
			case foarb::oichl: cout << "oichl "; break;
			case foarb::gros: cout << "gros "; break;
			case foarb::herz: cout << "herz "; break;
			case foarb::schelln: cout << "schelln "; break;		
		}

		switch(s){
			case schlog::siebener: cout << "siebener" << endl; break;
			case schlog::achter: cout << "achter" << endl; break;
			case schlog::neiner: cout << "neiner" << endl; break;
			case schlog::zehner: cout << "zehner" << endl; break;
			case schlog::unter: cout << "unter" << endl; break;
			case schlog::ober: cout << "ober" << endl; break;
			case schlog::kine: cout << "kine" << endl; break;
			case schlog::sau: cout << "sau" << endl; break;
		}
	}
};

void tausche(koartn &stapel, koartn &randi){
	koartn tmp = stapel;
	stapel = randi;
	randi = tmp;
}

void mischen(koartn *koartnArray){
	random_device rd;
	mt19937 gen(rd( ));
	uniform_int_distribution<int> dis(0, 31);
	for(int i = 0; i < 32; i++){
		tausche(koartnArray[i], koartnArray[dis(gen)]);
	}
}

int main() {
	
	koartn koartnArray[32];
	int count = 0;

	for(int i = 0; i < 4; i++){

		for(int j = 0; j < 8; j++){

			switch(i){
				case 0: koartnArray[count].f = foarb::oichl; break;
				case 1: koartnArray[count].f = foarb::gros; break;
				case 2: koartnArray[count].f = foarb::herz; break;
				case 3: koartnArray[count].f = foarb::schelln; break;
			}


			switch(j){
				case 0: koartnArray[count].s = schlog::siebener; break;
				case 1: koartnArray[count].s = schlog::achter; break;	
				case 2: koartnArray[count].s = schlog::neiner; break;	
				case 3: koartnArray[count].s = schlog::zehner; break;
				case 4: koartnArray[count].s = schlog::unter; break;
				case 5: koartnArray[count].s = schlog::ober; break;
				case 6: koartnArray[count].s = schlog::kine; break;
				case 7: koartnArray[count].s = schlog::sau; break;		
			}
			count++;				
		}
	}
		
	for(int i = 0; i < 32; i++){
	        koartnArray[i].print(); //AUSGABE vorm mischen
	}

	//random_shuffle(&koartnArray[0], &koartnArray[31]); //mischen mit Zeiger auf anfang des Arrays und Ende des Arrays (random_shuffle ist in std::)
	mischen(koartnArray);

	for(int i = 0; i < 32; i++){
		koartnArray[i].print(); //AUSGABE nachm mischen
	}

	return 0;
}
