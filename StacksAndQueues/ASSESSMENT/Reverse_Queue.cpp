#include <queue>

void reverseQueue(queue<int> &q) {
	// Write your code here
    if(q.empty()){
        return;
    }
    //delete []x;
    int a = q.front();
    q.pop();
    reverseQueue(q);
    q.push(a);
}
