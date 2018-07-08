#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <functional>
#include <thread>
#include <future>
#include <sstream>
using namespace std;

struct hardware {
	std::string vendor, name;
	unsigned int quantity;
	float cost, tax = 0.19;
};

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}
	
namespace myFuncs {
	function<void(hardware)> components = [](const hardware &h){cout << h.vendor << " "
	<< h.name << ": " << h.quantity << endl << h.cost << endl;};
	
	/*function<void(vector<hardware>)> mostExpensive = [](const vector<hardware> &vec){
		int exp;
		int ind;
		vector<int> prices;
		for(hardware h : vec){ prices.push_back(h.cost); }
		sort(prices.begin(), prices.end(), greater<int>());
		cout << prices[0] << endl;
		
	};*/
	
	template <typename T> function<void(vector<T> &)> filter1 = [] (vector<T> &vec){
		int count = 0;
		for (T t : vec){
			if ( t.cost < 500 )
				vec.erase(vec.begin()+count);
			count++;
		}
	};

	template <typename T> void discount(float p, vector<T> &vec){ 
		filter1<T>(vec);
		int count = 0;
		for (T t : vec) {
			t.cost = t.cost - t.cost * p;
			vec.erase(vec.begin() + count);
			vec.emplace(vec.begin() + count, t);
			count++;
		}
	}
	
}

class counter{
	
	public: 
	void plus(string id){ 
		count++;
		cout << id << " ist bei " << count << endl; 
	} 
	
	private: 
		int count = 0;
};

class threadHelper{
	public:
		threadHelper(int id){
			this->id = "Thread";
			this->id.append(IntToString(id));
		}
		
		void operator ()(counter &c) {
			for (int i = 0; i < 100; ++i)
				c.plus(id); }
	
	private: 
		string id;
	
};




int main(){

	vector<hardware> sortiment;
	hardware cpu, gpu, ram;
	cpu.vendor ="intel";
    cpu.name = "i7";
	cpu.quantity = 5;
	cpu.cost = 400.00;

	
	gpu.vendor = "Nvidia";
	gpu.name = "gtx1180";
	gpu.cost = 1180.00;
	gpu.quantity = 1;
	
	ram.vendor = "Corsair";
	ram.name = "DudelRam";
	ram.quantity = 6;
	ram.cost = 2000.00;
	
	sortiment.push_back(cpu);
	sortiment.push_back(gpu);
	sortiment.push_back(ram);
	//myFuncs::components(cpu);
	//myFuncs::mostExpensive(sortiment);
	
	myFuncs::discount(0.5, sortiment);
	
	for (auto a : sortiment)
		myFuncs::components(a);
	
	
	/*
	vector<thread> threadVector;
	for (int i = 0; i < 100; ++i){
		threadHelper helper(i);
		thread t(helper, ref(c));
		threadVector.push_back(move(t));
	}
	for (thread &t : threadVector){
		t.join();
	}*/
	
	return 0;
}
