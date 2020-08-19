#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
	// Write your code here
    int a = input.size();
    int *ar = new int[a];
    
    for(int i=0; i < a; i++){
        ar[i] = input.top();
        input.pop();
    }
    
    for(int i=0;i<a;i++){
        input.push(ar[i]);
    }
}
