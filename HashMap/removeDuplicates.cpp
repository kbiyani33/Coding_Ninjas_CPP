#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> removeDuplicates(int *a, int size){
    vector<int> op;
    unordered_map<int, bool> seen;

    for(int i=0; i<size; i++){
        if(seen.count(a[i]) > 0){
            continue;
        }
        seen[a[i]] = true;
        op.push_back(a[i]);
    }
    return op;
}

int main(){
    int a[] = {1, 2, 3, 2,3 ,2,4,34 ,2,3 ,412};
    vector<int> output = removeDuplicates(a, 11);
    for(int i=0; i<output.size();i++){
        cout << output[i] << endl;
    }
    return 0;
}