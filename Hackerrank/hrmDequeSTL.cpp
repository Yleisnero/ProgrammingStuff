#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){ //WATCH OUT: THIS WAY ISN´T WORKING FOR BIG ARRAYS .... :( Use this instead: 
					https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/#disqus_thread
	//Write your code here.
    int max;
    for(int i = 0; i <= n-k; i++){ //count of array = n
        max = arr[i];
        for(int j = i; j < k + i; j++){ //length of subarrays = k
            if(arr[j] > max){
                max = arr[j];
            }
        }
        cout << max << " ";
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
