#include "std_lib_facilities.h"

void sterne(int anzahl){

	for(int i = 1; i < anzahl+1; i++){
		for(int j = 1; j < anzahl+1; j++){
			if(j <= i){
				cout << j;
			}else{
				cout << '*';
			}
		}

		cout << endl;
	}

}


int main(){
	sterne(7);
	return 0;
}


