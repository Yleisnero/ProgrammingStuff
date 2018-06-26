#include <thread>
#include <iostream>
#include <vector>

int main(){

std::vector<std::thread> counters;

for(int i = 0; i < 100; i++){	
	counters.push_back(std::thread([](){
		for(int i = 0; i < 1000; i++){
			std::cout << i << std::endl;
		}	
	}));
}
	for(std::thread &t : counters){
		t.join();
	}
	return 0;
}
