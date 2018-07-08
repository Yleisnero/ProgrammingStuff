#include <thread>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){

	float array[100];
	vector<thread> threads;
	vector<float> negativ;
	
	for(int i = 0; i < 100; i++){
		array[i] = (i + 1) * sin(i / 3);
		cout << array[i] << endl;
	}	
	
	for(int i = 0; i < 10; i++){
		threads.push_back(thread([&negativ, i, &array](){
			for(int j = i*10; j < i*10 + 10; j++){
				if(array[j] < 0){
					negativ.push_back(array[j]);
				}
			}
		}));
	}

	for(thread &t : threads){
		t.join();
	}
	
	cout << "\nnegativ:\n";
	for(float &f : negativ){
		cout << f << endl;
	}
	

return 0;
}
