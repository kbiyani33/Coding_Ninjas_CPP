//Dynamic Push in stack similar to Dynamic array
//IMPORTANT W.R.T CHAR TEMPLATE STACK
//If we pass an integer after passing the stack to be char, it will treat the ineger values as ASCII Coded values.

#include<iostream>
using namespace std;
template<typename t>
class stack{
    //In this we will implement the basic operations of a stack using an array
    private:
    t *data ; //The array we want to use for implementaion of stack
    int  next ; //Since we will be getting the integer array, we need size
    int totsize ; //We need to keep track if the capacity is equal to totsize
    public:
    
    stack(){
        //Creating Prameterized Constructor.
        //We need the total size of the array from the user.
        this -> totsize = 5;
        this -> data = new t(totsize);
        this -> next = 0;
        
    }
    
    void push(const t &x){
        //let's check if the stack is full
        if(next == totsize){
            t *n2 = new t(totsize * 2);
            for(int i = 0; i < totsize ; i++){
                n2[i] = data[i];
            }
            delete []data;
            data = n2;
            totsize = totsize * 2;
            /*
            //For tatic Stack, the push function would simple cout stack full message
            cout << "EMPTY" << endl;
            return ; 
            */
        }
        //if not full 
        data[next] = x;
        next += 1;
    }
    
    int sizeofstack(){
        return next;
    }
    
    bool isempty(){
        return next ==0 ;
    }
    
    t pop(){
        
        if(isempty()){
            cout << "EMPTY"<<endl;
            return -1;
        }
        
        next--;
        return data[next];
    }
    
    t top(){
        if(isempty()){
            cout << "EMPTY"<<endl;
            return -1;
        }
        return data[next - 1];
    }
};


int main(){
    stack<char> s;
    
    s.push('a');
    s.push('b');
    s.push('f');
    s.push('g');
    s.push('t');
    
    cout << s.sizeofstack() << endl;
    cout << s.sizeofstack() << endl;
    cout << s.isempty() << endl;
    
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    //return 0;
    
}
