#ifndef AD_PROJECT_QUEUE_H
#define AD_PROJECT_QUEUE_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class queue {
    queue *next{};
    int element{};
    int size;

public:

    queue();

    //elements can be inserted at specified index
    void fill(int element, int index = -1);

    //overwrite elements with new array
    void overwrite(vector<int> arr);

    //while printing all elements per default, this function also serves as getter for elements at specified index
    vector<int> print(bool output = false, int index = -1);

    //play some lotto
    void play();

    int get_size();

};


#endif //AD_PROJECT_QUEUE_H
