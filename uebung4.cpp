#include "std_lib_facilities.h"


enum struct foarb : int {oichl = 1, gros = 2, herz = 3, schelln = 4};
enum struct schlog : int {siebener = 7, achter = 8, neiner = 9, zehner = 10, unter = 11, ober = 12, kine = 14, sau = 13 };

struct koartn {
	foarb f;
	schlog s;
};

int main() {
	
	koartn koartnArray[32];
	int count = 0;
	string farben[] = {"oichl", "gros", "herz", "schelln"};

	for(int i = 0; i < 4; i++){

			switch(i){
				case 0: koartnArray[count].f = foarb::oichl; break;
				case 1: koartnArray[count].f = foarb::gros; break;
				case 2: koartnArray[count].f = foarb::herz; break;
				case 3: koartnArray[count].f = foarb::schelln; break;
			}

		for(int j = 0; j < 8; j++){

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
	        foarb f = koartnArray[i].f;

	        switch(f){
		
		case foarb::oichl: cout << "oichl" << endl; break;

		case foarb::gros: cout << "gros" << endl; break;	
			
		}
	}

	return 0;
}

