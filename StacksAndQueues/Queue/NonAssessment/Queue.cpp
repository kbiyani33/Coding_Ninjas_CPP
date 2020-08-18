#include <iostream>
using namespace std;
//using array
template<typename t>
class queue{
    int first ;
    int next;
    int size;
    int capacity;
    t *data;
    
    public:
    queue(int capacity){
        this -> data = new t(size);
        nextIndex = 0;
        first = -1;
        this -> size = 0;
        capacity = size;
    }
    
    int getsize(){
        return size;
    }
    
    bool isEmpty(){
        return size == 0;
    }
    
    void enqueuq(t a){
        if(size == capacity){
            cout << "QUEUE FULL" << endl;
            return ;
        }
        if(first == -1){
            
            first = 0 ;
            
        }
        data[next] = t;
        size += 1;
        next = ( next + 1 ) % capacity;
        
    }
    
    t front(){
        if(isEmpty()){
            cout << "QUEUE EMPTY" << endl;
            return -1;
        }
        return data[first] ;
    }
    
    t dequeue(){
        if(isEmpty()){
            cout << "QUEUE EMPTY" << endl;
            return -1;
        }
        int a = first;
        first = (first + 1) % capacity;
        size -= 1;
        if(size == 0){
            first = -1;
            next = 0;
        }
        return data[a];
    }
}
