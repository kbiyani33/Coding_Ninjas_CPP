#include <iostream>
#include<unordered_map>
// #include<bits/stdc++.h>
using namespace std;

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> op;
    for(int i = 0 ; i < n ; i++){
        if(op.count(arr[i]) > 0){
            op[arr[i]] += 1;
        }
        else
        	op[arr[i]] = 1;
    }
    int m = INT_MIN;
    int res = 0;
    for(int i = 0 ; i < n ; i++){
        if(op[arr[i]] > m){
            m = op[arr[i]];
            res = arr[i];
        }
        
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}