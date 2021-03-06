//Dynamic Push in stack similar to Dynamic array
#include<iostream>
using namespace std;
class stack{
    //In this we will implement the basic operations of a stack using an array
    private:
    int *data ; //The array we want to use for implementaion of stack
    int  next ; //Since we will be getting the integer array, we need size
    int totsize ; //We need to keep track if the capacity is equal to totsize
    public:
    
    stack(){
        //Creating Prameterized Constructor.
        //We need the total size of the array from the user.
        this -> totsize = 5;
        this -> data = new int(totsize);
        this -> next = 0;
        
    }
    
    void push(const int &x){
        //let's check if the stack is full
        if(next == totsize){
            int *n2 = new int(totsize * 2);
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
        if(next > 0)
            return false;
        else
            return true;
    }
    
    int pop(){
        
        if(isempty()){
            cout << "EMPTY"<<endl;
            return -1;
        }
        
        next--;
        return data[next];
    }
    
    int top(){
        if(isempty()){
            cout << "EMPTY"<<endl;
            return -1;
        }
        return data[next - 1];
    }
};


int main(){
    stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    s.push(110);
    
    cout << s.sizeofstack() << endl;
    cout << s.sizeofstack() << endl;
    cout << s.isempty() << endl;
    
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    
}
