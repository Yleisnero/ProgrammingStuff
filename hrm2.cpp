#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class BadLengthException { //tried to inherit public exception, somehow don't wanted to print const char* ¯\_(ツ)_/¯
    public:			//its working with : public exception for me (Jonas) 
    BadLengthException(int n) : n(n){}
    virtual const int what(){
        return n;
    }
    private: int n;
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException& e) {
			cout << "Too short: " << e.what() << endl;
		}
	}
	return 0;
}
