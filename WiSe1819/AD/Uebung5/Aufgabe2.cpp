#include <iostream>

bool isAdditionAvailable(int *, int, int);
void heapSort(int *, int, int);
void heapify(int *, int, int);
void buildMaxHeap(int *, int);
void swap(int &, int &);


int main() {
    int a[] =  {5, 2, 7, 19, 6, 9};
    int n = 6;
    int erg = 1;

    isAdditionAvailable(a, n, erg) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    return 0;
}

bool isAdditionAvailable(int *a, int length, int erg){
    heapSort(a, a[0], length);

    int i = 0, j = length-1;

    while(i < j){
        if(a[i] + a[j] == erg){
            return true;
        }else if(a[i] + a[j] < erg){
            i++;
        }else{
            j--;
        }
    }
    return false;
}

void heapSort(int *a, int first, int length){
    buildMaxHeap(a, length);
    for(int i = length; i > 0; i--){
        swap(a[0], a[i]);
        heapify(a, i - 1, 0);
    }
}

void heapify(int *a, int length, int root){
    int largest, left = (root)*2+1, right = root*2+2;

    if(left <= length && a[left] > a[root]){
        largest = left;
    } else{
        largest = root;
    }

    if(right <= length && a[right] > a[largest]){
        largest = right;
    }

    if(largest != root){
        swap(a[root], a[largest]);
        heapify(a, length, largest);
    }
}

void buildMaxHeap(int *a, int length){
    for(int i = (length-1)/2; i >= 0; i--){
        heapify(a, length, i);
    }
}

void swap(int &a, int &b){
    int storage = a;
    a = b;
    b = storage;
}

