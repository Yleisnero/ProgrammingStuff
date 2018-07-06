#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int numHoles(int num){

	vector<int> ints;

	int teiler;

	for(int i = 10; num/i > 0; i = i * 10){
		teiler = i;
	} 

	for(int i = teiler; i >= 10; i = i / 10){
		ints.push_back(num / i);
		num = num % i;
	}
	ints.push_back(num);

/*
	//Ausgabe der Bestandteile
	for(int i : ints){
		cout << i << " ";
	}
	cout << endl;
*/
	int holes;
	for(int i : ints){
		switch(i){
			case 0: holes++;	break;
      			case 4: holes++;  	break;
      			case 6: holes++;  	break;
      			case 8: holes += 2; 	break;
     			case 9: holes++; 	break;
			default: break;
		}
	}

return holes;

}

int main()  {
  cout << "num of Holes: " << numHoles(1111) << endl;
  return 0;
}
