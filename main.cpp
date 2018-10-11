#include <iostream>
using namespace std;

int testTriangle (short a, short b, short c){
    int x;
    if(a>0 && b>0 && c>0){

        if(a+b>c || b+c>a || a+c>b){

            if(a==b==c){
                return x=3;
            } else{
                if(a==b||b==c||a==c){
                    return x=2;
                } else{
                    return x=1;
                }
            }
        }
        else{
            return x=0;
        }
    }
    else{
        return x=0;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}