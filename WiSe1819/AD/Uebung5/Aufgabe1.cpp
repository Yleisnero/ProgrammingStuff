#include <iostream>

void print(int *a, int length);

void mergeSort(int *a, int first, int length);
void merge(int *a, int first, int length, int mid);

void heapSort(int *, int, int);
void heapify(int *, int, int);
void buildMaxHeap(int *, int);
void swap(int &, int &);

int main() {

    int a[] = {-5, 12, -32, 7, -3, 17, 23, 12, -35, 19};

    std::cout << "Mergesort: " << std::endl;
    mergeSort(a, 0, 9);
    print(a, 10);

    int a2[] = {-5, 12, -32, 7, -3, 17, 23, 12, -35, 19};

    std::cout << "Heapsort: " << std::endl;
    heapSort(a2, 0, 9);
    print(a2, 10);

    return 0;
}

void print(int *a, int length){
    for(int i = 0; i < length; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void mergeSort(int *a, int first, int length){

    if(first < length){
        int mid = (first + length + 1) / 2;
        mergeSort(a, first, mid - 1);
        mergeSort(a, mid, length);

        merge(a, first, length, mid);
    }

}

void merge(int *a, int first, int length, int mid){

    int n = length - first + 1;
    int a1first = first;
    int a1last = mid - 1;
    int a2first = mid;
    int a2last = length;
    int *anew = new int[n];

    for(int i = 0; i < n; i++){

        if(a1first <= a1last){
            if(a2first <= a2last){
                if(a[a1first] <= a[a2first]){
                    anew[i] = a[a1first++];
                }else{
                    anew[i] = a[a2first++];
                }
            }else{
                anew[i] = a[a1first++];
            }
        }else{
            anew[i] = a[a2first++];
        }
    }

    for(int i = 0; i < n; i++){
        a[first + i] = anew[i];
    }

    delete [] anew;

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