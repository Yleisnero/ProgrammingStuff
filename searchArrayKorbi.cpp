#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

mutex iterMutex;

int main(){
	
	int array[] = { 654,65,65,56,654,54,68,464,6,46,46,46,46,5,4,2,1,34,98,651,81,65,12,178,1,21,1,78,1,4124,16,861 };
	vector<thread> threadVector;
	int tAnzahl;
	cin >> tAnzahl;
	int begin, end, count = 0;
	for (int i = 0; i < tAnzahl; i++){
		cout << "Gimme a Iterator: " << endl;
		cin >> begin >> end;
		thread t ([&]{ for (; begin < end; begin++){
			iterMutex.lock();
			if (array[begin] == 1){
				count++;
			}
			iterMutex.unlock();
		} });
		threadVector.push_back(move(t));
	}
	
	for (thread &t : threadVector){
		t.join();
	}
	
	cout << count << endl;
	
	return 0; 
}
