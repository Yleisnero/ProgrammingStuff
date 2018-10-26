#include <iostream>

void Insertionsort(int*, int);
void ReverseInsertionsort(int *, int);
void Bubblesort(int*, int);
void ReverseBubblesort(int *, int);
void SelectionSort(int *, int);
void print(int*, int);

int main() {
    int nums[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    int length = 10;
/*
    std::cout << "Insertionsort: " << std::endl;
    Insertionsort(nums, length);
*/
    int nums_2[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    std::cout << std:: endl << "Bubblesort: " << std::endl;
    Bubblesort(nums_2, length);
/*
    int nums_3[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    std::cout << std:: endl << "SelectionSort: " << std::endl;
    SelectionSort(nums_3, length);
*/
    int nums_4[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    std::cout << std:: endl << "ReverseInsertionsort: " << std::endl;
    //ReverseInsertionsort(nums_4, length);

    int nums_5[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    std::cout << std:: endl << "ReverseBubblesort: " << std::endl;
    ReverseBubblesort(nums_5, length);

    return 0;
}

void Insertionsort(int *nums, int length){
    int key, j;

    for(int i = 1; i < length; i++){
        key = nums[i];
        j = i-1;

        while(j >= 0 && nums[j] > key){
            nums[j+1] = nums[j];
            j--;
            print(nums, length);
        }

        nums[j+1] = key;
        print(nums, length);
    }
}

void ReverseInsertionsort(int *nums, int length){ //?????????????????????
    int key, j;

    for(int i = 1; i < length; i++){
        key = nums[i];
        j = i-1;

        while(j < length && nums[j] < key){
            nums[j] = nums[j+1];
            j++;
            print(nums, length);
        }

        nums[j-1] = key;
        print(nums, length);
    }
}

void Bubblesort(int *nums, int length){
    for(int i = 0; i < length; i++){
        for(int j = length - 2; j >= i; j--){
            if(nums[j] > nums[j+1]){
                int storage = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = storage;
                print(nums, length);
            }
        }
    }
}

void ReverseBubblesort(int *nums, int length){
    for(int i = length; i >= 0; i--){
        for(int j = 2; j < i; j++){
            if(nums[j] < nums[j+1]){
                int storage = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = storage;
                print(nums, length);
            }
        }
    }
}

void SelectionSort(int *nums, int length){
    int j, min;
    for(int i = 0; i < length; i++){
       min = i;
       for(j = i; j < length; j++){
           if(nums[j] < nums[min]){
               min = j;
           }
       }

       int storage = nums[i];
       nums[i] = nums[min];
       nums[min] = storage;
       print(nums, length);
    }
}

void print(int *a, int n){
    for(int x = 0; x < n; x++){
        std::cout<< a[x] << " ";
    }
    std::cout << std::endl;
}