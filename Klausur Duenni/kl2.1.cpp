#include <iostream>
using namespace std;

class sequence {
	private: 
		string toDelete;
	public: 
		sequence(string input): toDelete(input){}
		
		//not working with foreach -> has to be done with normal for see Zindys and Joshis way
		string &without(char delimiter, int &n){
			int count = 0;
			n = 0;
			for (char c : toDelete){
				if(c == delimiter){
					toDelete.erase(toDelete.begin()+count);
					n++;
				} else count++;
			}
			
			/* n= 0;
			string *result = new string(toDelete);
			result->clear();
			for (char c : toDelete){
				if (c != delimiter){
					result->append(1, c);
				} else n++;
			} /*HARD VARIANT*/
			
			/* Zindy and Joshis way
			n = 0;
			for(int i = 0; toDelete[i] != '\0'; i++){
				if(toDelete[i]==delimiter){
					toDelete.erase(toDelete.begin()+i);
					n++;
					i--;
					
				}
			} */
			return toDelete;  // *result for HARD VARIANT */;
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
