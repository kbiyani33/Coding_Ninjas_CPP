#include<iostream>
#include<vector>
using namespace std;

class ComplexNumbers {
    // Complete this class
    //Class Attributes
    private:
    int real,imag;
    //First we need to create a parameterized constructor
    public:
    ComplexNumbers(int real, int imag){
        this -> real=real;
        this -> imag=imag;
    }
    void print(){
        cout<<real<<" + i"<<imag<<endl;
    }
    void plus(ComplexNumbers const &c2){
        this ->real=(this ->real)+c2.real;
        this ->imag=(this ->imag)+c2.imag;
    }
    
    void multiply(ComplexNumbers const &c2){
        //getting the real
        int x=this ->real;
        int y=this ->imag;
        real=x*c2.real - y*c2.imag;
        //getting imaginary
        imag=x*c2.imag+y*c2.real;
    }
    
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}
