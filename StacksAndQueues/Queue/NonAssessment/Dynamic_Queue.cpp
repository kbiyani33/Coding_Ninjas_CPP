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
    queue(){
        this -> capacity = 4;
        this -> data = new t(capacity);
        next = 0;
        first = -1;
        this -> size = 0;
    }
    
    int getsize(){
        return size;
    }
    
    bool isEmpty(){
        return size == 0;
    }
    
    void enqueue(t a){
        if(size == capacity){
            t *newd = new t(capacity * 2);
            //first copying from the first element
            int  j = 0;
            for(int i = first; i < capacity ; i++){
                newd[j] = data [i];
                j += 1;
            }
            for(int i = 0;i < first ; i++){
                newd[j] = data [i];
                j += 1;
            }
            capacity = capacity * 2;
            first = 0;
            next = capacity ;
            delete []data;
            data = newd ;
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
    
    int cap(){
        return capacity;
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
   queue<int> q;
   cout <<"size " << q.getsize() << endl;
   cout << "capacity" << q.cap() << endl;
   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   cout << q.dequeue() << endl ;
   cout << q.dequeue() << endl ;
   q.enqueue(4);
   q.enqueue(5);
   q.enqueue(6);
   q.enqueue(7);
   
   
   cout <<"size " << q.getsize() << endl;
   cout << "capacity" << q.cap() << endl;
   
   
   cout << q.dequeue() << endl ;
   cout << q.dequeue() << endl ;
   cout <<"size " << q.getsize() << endl;
   cout << q.dequeue() << endl ;
   cout << q.dequeue() << endl ;
   cout << q.dequeue() << endl ;
   cout << q.front() << endl;
   
   return 0;
}
