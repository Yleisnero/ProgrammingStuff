/*
 * Source: https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/
 */

#include <iostream>
#include <string.h>

#define ROW 5
#define COL 5

int maxTeilsum3(int[], int, int&, int&);
void maxTeilsum2D(int[][COL]);

int main() {
    /*
        int nums[] = {5,0,-7,19,3};
        int n = sizeof(nums) / sizeof(int);
        int start = 0, finish = 0;

        std::cout << maxTeilsum3(nums, n, start, finish) << " from " << start << " to " << finish << std::endl;
    */

    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
    };

    maxTeilsum2D(M);

    return 0;
}

void maxTeilsum2D(int M[][COL]){
    int max =  std::numeric_limits<int>::min();
    int finalLeft = 0, finalRight = 0, finalTop = 0, finalBottom = 0;

    int left, right; //Temp variables
    int temp[ROW], sum = 0, start = 0, finish = 0;

    //Set the left column
    for(left = 0; left < COL; ++left){
        //Set every element of temp 0
        memset(temp, 0, sizeof(temp));

        for(right = left; right < COL; ++right){ //Try out every possible MaxTeilsum2d

            for(int i = 0; i < ROW; ++i){
                temp[i] += M[i][right];
            }
            sum = maxTeilsum3(temp, ROW, start, finish); //search for MaxTeilsum in one row with MaxTeilsum3 (Kadane Algorithmus)

            if(sum > max){ //Check if sum ist bigger than max
                max = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    std::cout<< "Left: " << finalLeft << " Top: " << finalTop << " Right: " << finalRight << " Bottom: " << finalBottom << std::endl;
    std::cout << "MaxSum: " << max << std::endl;

    //Print the MaxTeilsum 2D
    for(int i = finalLeft; i <= finalRight; i++){
        for(int j = finalTop; j <= finalBottom; j++){
            std::cout << M[i][j] << " ";
        }
        std::cout<<std::endl;
    }

}

int maxTeilsum3(int *a, int size, int &start, int &finish){
    int storage, max = std::numeric_limits<int>::min(), aktSum = 0;
    start = 0;
    finish = 0;

    for(int i = 0; i < size; i++){
        storage = aktSum + a[i];
        if(storage > a[i]){
            aktSum = storage;
        }else{
            aktSum = a[i];
            start = i;
        }

        if(aktSum > max){
            max = aktSum;
            finish = i;
        }
    }

    return max;
}