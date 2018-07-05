#include <thread>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;
			
class frog { 

	private: int ways; int numberOfWays(int n){
				if(n == 1)
					return n;
				if(n == 2)
					return n;
				return numberOfWays(n-1) + numberOfWays(n-2);
			}
	public: void go(int n) { ways = numberOfWays(n); }
			int possibilities() { return ways; } 
			

};

int main(void) {
	vector<thread> threads; vector< frog *> frogs;
	for (int i = 0; i < 5; i++) {
		frog *frogger;
		frogs.push_back(frogger = new frog());
		threads.push_back(thread([=](){ frogger->go(i + 3); }));  //Original
		//threads.push_back(thread([frogger, i](){ frogger->go(i + 3); })); } 2.4
		/*function <void()> r = [frogger, i](){ frogger->go(i + 3); };
		threads.push_back(thread(r)); 2.5 */
		}
	for(thread &t : threads) t.join();
	for (int i = 0; i < 5; i++) {
		frog *frogger = frogs[i]; cout << "frog " << i + 1 << " has "
		  << frogger->possibilities() << " possibilities" << endl;
		delete frogger;
	}
	return 0;
}