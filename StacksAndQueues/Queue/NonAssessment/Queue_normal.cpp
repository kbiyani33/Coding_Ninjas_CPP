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
        this -> data = new t(capacity);
        next = 0;
        first = -1;
        this -> size = 0;
        this -> capacity = capacity;
    }
    
    int getsize(){
        return size;
    }
    
    bool isEmpty(){
        return size == 0;
    }
    
    void enqueue(t a){
        if(size == capacity){
            cout << "QUEUE FULL" << endl;
            return ;
        }
        if(first == -1){
            
            first = 0 ;
            
        }
        data[next] = a;
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
        t a = data[first];
        first = (first + 1) % capacity;
        size -= 1;
        if(size == 0){
            first = -1;
            next = 0;
        }
        return a;
    }
};


int main()
{
   queue<int> q(5);
   cout << q.getsize() << endl;
   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   q.enqueue(4);
   q.enqueue(5);
   
   q.enqueue(6);
   cout << q.dequeue() << endl ;
   cout << q.dequeue() << endl ;
   cout << q.dequeue() << endl ;
   cout << q.dequeue() << endl ;
   cout << q.dequeue() << endl ;
   cout << q.front() << endl;
   
   return 0;
}
