#include "std_lib_facilities.h"
#include <math.h>

int f(int x){ //f(x)= x^3-1
	
return pow(x,3) - 1;

}

int bisect(int a, int b, int (*f)(int)){ //Epsilon: 1
    // Halbierung
    int mitte = a + (a+b)/2;

    if(f(mitte) == 0){
       cout << mitte << " ist nullstelle" << endl;
    }else{

	if(b - a == 1){
            return a;
	}  else  {
		if((f(a) > 0 && f(mitte) < 0) || (f(a) < 0 && f(mitte) > 0)){
			bisect(a, mitte, f);
		}else{
			bisect(mitte, b, f);
		}

	}	
}
}

int main(){
  int a = 0;
  int b = 5; //intervall

  cout << bisect(a, b, f);


  return 0;
}


