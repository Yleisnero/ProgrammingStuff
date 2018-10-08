#include <iostream>
#include <stdlib.h>
using namespace std;

class Feld{
	int length;
	int *data;
	public:
	void init(int l){
		data = new int[length = l];
		for(int i = 0; i < length; i++){
			data[i] = 0;
		}
	}

	void fillRandom(){
		for(int i = 0; i < length; i++){
			data[i] = rand() % 1000 + 1;
		}
	}

	int min(){
		int result = data[0];
		for(int i = 1; i < length; i++){
			if(data[i] < result){
				result = data[i];
			}
		}
		return result;
	}

	int max(){
		int result = data[0];
		for(int i = 1; i < length; i++){
			if(data[i] > result){
				result = data[i];
			}
		}
		return result;
	}

	int avg(){
		int result = 0;
		for(int i = 0; i < length; i++){
			result += data[i];
		}
		return result/length;
	}

	void print(){
		for(int i = 0; i < length; i++){
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

int main(){
	Feld f;
	f.init(10);
	f.fillRandom();
	f.print();
	cout << f.max() << endl;
	cout << f.min() << endl;
	cout << f.avg() << endl;
	return 0;
}
