#include <iostream>
#include <vector>
#include <thread>
#include <math.h>

using namespace std;

class myNum{
	public:
	myNum(int n) : num(n){ mark = false; }

	bool getMark(){
		return mark;
	}

	int getNum(){
		return num;
	}
	
	void setMark(bool b){
		mark = b;
	}

	private:
	int num;
	bool mark; //true ist keine primzahl
};

void sieb(int count){
	vector<myNum> nums;
	for(int i = 2; i <= count; i++){ //alle Zahlen, 2 hat index 0	
		nums.push_back(myNum(i));
	}
	
	for(int i = 0; i < count-1; i++){
				
			myNum zahl = nums[i]; //aktuell Zahl
			cout << nums[i].getNum();
			if(zahl.getMark() != true){
				for(int j = i + zahl.getNum(); j <= count; j = j + zahl.getNum()){
					nums[j].setMark(true);
				}
				cout << " prim" << endl;
			}else{
				cout << endl;
			}
		
	}
}

int main(){

	sieb (100);

return 0;
}
