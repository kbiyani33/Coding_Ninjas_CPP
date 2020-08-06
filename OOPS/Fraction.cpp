#include<iostream>
using namespace std;

class Fraction{
    private:
    int num, den;
    
    public:
    
    //Parameterized constructor to prevent garbage values
    Fraction(int num, int den){
        this -> num=num;
        this -> den=den;
    }
    
    //A function to print
    void print(){
        cout<<this -> num<<"/"<<this -> den<<endl;
        /*Since there's no confusion, we can ignore this
        However it is to show that the object has the pointer to attributes
        in this
        cout<<num<<"/"<<den<<endl;//this statement works too
        */
    }
    /*Now let's create a function to add two fractions
    1) We get two questions, what are the number of parameters in the function?
    
    Ans) We need just one parameter, that is the object of the same class holding the second value we want to add. if the name of our class is add, we will call it from main using F1.add(). In this case, the this pointer has the values of num and den of F1. We only need to add the second object as, F1.add(F2);
    
    
    2) What's the return type?
    Ans) The function let's say adds F1 and F2 and stores the result in F1 itself, thus we can use this to get the values in F1 itself. Thus we can keep the return type as void
    
    */
    void simplify(){
        //it has no parameters, hence it simplifies the fraction in the this
        int gcd=1;
        int m=min(this -> num,this -> den);//same as min(num,den)
        for(int i=1;i<=m;i++){
            if(num%i==0 && den%i==0){
                gcd=i;
            }
        }
        this -> num=(this -> num)/gcd;
        this -> den=(this -> den)/gcd;
    }
    /*
    void add(Fraction const &F2){
        int lcm=(this -> den)*F2.den;//same as den*F2.den
        int x=(this -> num)/lcm;//same as num/lcm
        int y= F2.num/lcm;
        
        int n=(this -> num)*x+F2.num*y;//same as num+F2.num*y
        this -> num=n;
        this -> den=lcm;
        
        simplify();
    }
    
    void multiply(Fraction const &F2){
        num=num*F2.num;
        den=den*F2.den;
        
        simplify();
    }
    */
    //Now we wish to change the functionality such that, '+' can be used inplace of sum
    
    //First let's write a function of add, that takes the fraction and saves the sum in third variable
    
    Fraction add(Fraction const &F2){
        int lcm=(this -> den)*F2.den;
        int x=lcm/(this -> den);
        int y=lcm/F2.den ;
        
        int n=(this -> num)*x+F2.num*y;
        Fraction F3(n,lcm);
        F3.simplify();
        return F3;
    }
    //Now how to overload "+" operator to add the two fractions as we have given?
    //When we write, F1+F2, the sum of fractions is to be saved in our thing
    //The whole function remains the same, only the name is changed as follows:
    
    Fraction operator+(Fraction const &F2){
        int lcm=(this -> den)*F2.den;
        int x=lcm/(this -> den);
        int y=lcm/F2.den ;
        
        int n=(this -> num)*x+F2.num*y;
        Fraction F3(n,lcm);
        F3.simplify();
        return F3;
    }
    
    Fraction operator*(Fraction const &F2){
        int n=(this -> num)*F2.num;
        int d=(this -> den)*F2.den;
        Fraction F(n,d);
        F.simplify();
        return F;
    }
    //overloading preincrement in F1 and storing in the same one
    /*
    void operator++(){
        this -> num=this -> num+this -> den;
        this -> den=this -> den;
        
        simplify();
    }
    
    int i=5;
    int j=++i;
    cout<<i<<" "<<j<<endl;
    
    OUTPUT:
    6 6
    
    But when we do this to our current void function, it is not posslibe since return type is Void. 
    
    so, first we want to return a Fraction, and what do we want to really return?
    
    When we write the statement, int j=++i; 
    We actually update i then copy it in j, so when dealing with objects, we want to copy it in with a copy constructor. 
    in objects, the statement, 
    class_name onj2=obj1; this copies the content of obj1 in obj2, i.e. all the attributes, so to get that returned we can return *(this)
    */
    //NEW FUNCTION
    Fraction& operator++()//using & there to prevent a copy
    {
        this -> num=this -> num+this -> den;
        this -> den=this -> den;
        
        simplify();
        return *(this);
    }
    //Let's write a post increment operator
    Fraction operator++(int) //we use int in brackets here for post 
    {
        //we don't have nesting needed for post increment.
        Fraction fnew(num, den);
        num=num+den;
        simplify();
        fnew.simplify();
        return fnew;
    }
    //let's implement, shorthand operator
    
    Fraction& operator+=(Fraction const &F2)//this function cannot do nesting so we return Fraction type
    {
        int lcm=(this -> den)*F2.den;
        int x=lcm/(this -> den);
        int y=lcm/F2.den ;
        
        int n=(this -> num)*x+F2.num*y;
        num=n;
        den=lcm;
        simplify();
        return *(this);
    }
    
};


int main(){
    Fraction F1(10,2);
    Fraction F2(15,4);
    cout<<"original"<<endl;
    F1.print();
    F2.print();
    Fraction F3(12,7);
    F1+=(F2+=F3);
    F1.print();
    F2.print();
    /*
    Fraction f3=F1++;
    f3.print();
    F1.print();
    
    
    Fraction f2=++(++F1);
    F1.print();
    f2.print();
    
    cout<<"add"<<endl;
    Fraction F3=F1.add(F2);
    Fraction F4=F1+F2;//This adds in the same way. The Object before + is in this
    Fraction F5=F1*F2;
    ++F1;
    F1.print();
    F2.print();
    F3.print();
    F4.print();
    F5.print();
    */
    return 0;
}
