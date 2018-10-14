/* Simple wrapper for switch case on strings
   Function returns position in vector cases -> can be used in normal switch case*/
#ifndef STRING_SWITCH
#define STRING_SWITCH
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

unsigned long long int string_switch(string switch_statement, vector<string> cases){
    unsigned long long int pos = 0;
    for (unsigned long long int i = 0; i < cases.size(); i++) {
        for (int j = 0; j < size(cases.at(i)); j++) {
            if (cases.at(i)[j] == switch_statement[j]) {
                pos = i + 1;
                if (j + 1 == size(cases.at(i))) {
                    return pos;
                }
            } else {
                pos = 0;
                break;
            }
        }
    }
    return pos;
}
    

#endif //STRING_SWITCH
