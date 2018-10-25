#include <iostream>

void Insertionsort(int*, int);
void Bubblesort(int*, int);
void print(int*, int);

int main() {
    int nums[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};

    Insertionsort(nums, 10);
    for(int e : nums){
        std::cout << e << " ";
    }
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

void Bubblesort(int *nums, int length){
    for(int i = 0; i < length; i++){
        for(int j = length - 2; j >= i; j--){
            if(nums[j] > nums[j+1]){
                int storage = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = storage;
            }
        }
    }
}

void print(int *a, int n){
    for(int x = 0; x < n; x++){
        std::cout<< a[x] << " ";
    }
    std::cout << std::endl;
}