#include <iostream>
using namespace std;

//Let's make a dynamic array using class

class DynamicArray{
    /*
    What's the plan?
    Take an internal array, of a fixed initial size, and will ask user to pass elements. Once we have an a new input from the user that exceeds the initial size, we will double the size of the array.
    */
    
    int *data;
    int capacity;
    int nextIndex;//to make us know, which index we want to add the user input element
    
    public:
    //constructor
    DynamicArray(){
        data=new int(5);
        nextIndex=0;
        capacity=5;
        for(int i=0;i<capacity;i++){
            data[i]=0;
        }
    }
    
    DynamicArray(DynamicArray const &d){
        //this -> data=d.data//this is shallow copy
        this -> data=new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++){
            this -> data[i]=d.data[i];
        }
        this -> nextIndex =d.nextIndex;
        this -> capacity  =d.capacity;
        
    }
    //function to add user element
    void add_element(int element){
        if(nextIndex==capacity){
            
            int *new_data=new int(2*capacity);
            for(int i=0;i<capacity;i++){//double array size, after it reaches capacity
                new_data[i]=data[i];
            }
            delete []data;
            data=new_data;
            capacity*=2;
        }
        data[nextIndex]=element;
        nextIndex+=1;
    }
    //get element at index i
    int get_element(int i){
        if(i>=nextIndex){
            return -1;
        }
        return data[i];
    }
    //change element at index i
    void replace(int i, int element){
        if(i<nextIndex){
            data[i]=element;
        }
        else if (i==nextIndex){
            add_element(element);
        }
        else{
            return;
        }
    }
    //print the array
    void print(){
        for(int i=0;i<nextIndex;i++){
            cout<<data[i]<<" ";
        cout<<endl;
        }
    }
    
    
    
    void operator=(DynamicArray const &d){
        //this -> data=d.data//this is shallow copy
        //we will use deep copy
        this -> data=new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++){
            this -> data[i]=d.data[i];
        }
        this -> nextIndex =d.nextIndex;
        this -> capacity  =d.capacity;
    }
    
};

int main()
{
   DynamicArray d1;
   d1.add_element(10);
   d1.add_element(20);
   d1.add_element(30);
   d1.add_element(40);
   d1.add_element(50);
   d1.add_element(60);
   d1.print();
   DynamicArray d2=d1;
   d1.replace(0,100);
   d1.print();
   d2.print();
}
