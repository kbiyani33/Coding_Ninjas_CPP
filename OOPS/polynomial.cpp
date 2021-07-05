#include<iostream>
#include<vector>
using namespace std;

class Polynomial {
    int *degCoeff;// Name of your array (Don't change this)
    int capacity;
    int next;
    
    
    // Complete the class
    public:
    
    Polynomial(){
        degCoeff=new int(5);
        for(int i=0;i<5;i++){
            degCoeff[i]=0;
        }
        next=0;
        capacity=5;
    }
    
    void print(){
        for(int i=0;i<next;i++){
            if(degCoeff[i]!=0){
                cout<<degCoeff[i]<<"x"<<i;
            }
        }
        cout<<endl;
    }
    
    Polynomial(Polynomial const &p2){
        this -> degCoeff = new int(p2.capacity);
        for(int i=0;i<p2.next;i++){
            this -> degCoeff[i]=p2.degCoeff[i];
        }
        this -> capacity=p2.capacity;
        this -> next=p2.next;
    }
    
    void operator=(Polynomial const &p2){
        this -> degCoeff = new int(p2.capacity);
        for(int i=0;i<p2.next;i++){
            this -> degCoeff[i]=p2.degCoeff[i];
        }
        this -> capacity=p2.capacity;
        this -> next=p2.next;
    }
    
    Polynomial operator*(Polynomial const &p){
        Polynomial p3;
        for(int i=0;i<capacity;i++)
        {
            for(int j=0;j<p.capacity;j++)
            {
                int degree= i+j;
                int coeff= p3.get(degree)+ degCoeff[i]*p.degCoeff[j];
                p3.setCoefficient(degree, coeff);
            }
        }
        return p3;
    }
    
    
};
