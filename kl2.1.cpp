#include <iostream>
using namespace std;

class sequence {
	private: 
		string toDelete;
	public: 
		sequence(string input): toDelete(input){}
		
		string without(char delimiter, int &n){
			int count = 0;
			n = 0;
			for (char c : toDelete){
				if(c == delimiter){
					toDelete.erase(toDelete.begin()+count);
					n++;
				}
				count++;
			}
			return toDelete;
		}
	
};

int main(){
	
	cout << "enter a string: ";
	string input;
	cin >> input;
	sequence sample(input);
	cout << "enter a char to be deleted from " << input << ": ";
	char vic; int n;
	cin >> vic;
	string result = sample.without(vic, n);
	cout << "result: " << result << endl
		 << "(deleted " << n << " occurences of " << vic << ")" << endl;
	return 0;
}