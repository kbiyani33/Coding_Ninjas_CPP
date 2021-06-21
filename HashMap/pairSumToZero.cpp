#include <iostream>
#include<unordered_map>
using namespace std;

int pairSum(int *input, int n) {
	// Write your code here
    unordered_map <int,int > m;
    int c = 0;
    
    
    for(int i = 0; i < n; i++){
        c += m[-1 * input[i]];
        m[input[i]] += 1;
    }
    
    
    return c;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}