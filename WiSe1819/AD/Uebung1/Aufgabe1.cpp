#include <iostream>
using namespace std;

int euklid(int, int);
int euklidRek(int, int, int);
int kgV(int, int);

int main() {
	int a = 31;
	int b = 39;
	cout << euklid(a, b) << endl;
	//cout << euklidRek(a, b, 0) << endl;
	cout << kgV(a, b) << endl;
	cout << a*b << endl; //Es fällt auf: kgV oft sehr groß nahe a*b und ggT nahe an 1
	return 0;
}

int euklid(int a, int b){ //sinnvoller, da weniger Übergabe (logischer für Anwender und resourcenschonender)
	int r;
	do{
		r = a % b;
		a = b;
		b = r;
	}while(r != 0);

	return a;
}

int euklidRek(int a, int b, int r){
	r = a%b;
	a = b;
	b = r;
	if(r == 0){
		return a;
	}else{
		return euklidRek(a, b, r);
	}
}

int kgV(int a, int b){
	int min = a < b ? a : b;
	int result = a*b;
	for(int i = result; i > 0; i = i - min){
		if(i%a == 0 && i%b == 0){
			result = i;
		}
	}
	return result;
}
