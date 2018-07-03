#include <thread>
#include <iostream>
#include <vector>
 
class SharedCounter{

	SharedCounter(){
		count = 0;
	}
	
	public:
	void plusOne(){
		this->count++;
	}
	
	int getCount(){
		return count;
	}	

	private:
	int count;


};

void counter(){
	for(int i = 0; i < 100; i++){
		std::cout << i << std::endl;
	}
}

int main(){

	SharedCounter sh();

	std::vector<std::thread> workers;

	for(int i = 0; i < 100; i++){
		workers.push_back(std::thread(sh.plusOne()));
		std::cout << sh.getCount() << std::endl;
	}

	for(std::thread &thread : workers){
		thread.join();
	}
	

return 0;
}

