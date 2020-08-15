//Let's make a triplet using a pair class with two values

template<typename T, typename V>
class pair2{
    T x;
    V y;
    
    public:
    void setX(T x){
        this -> x = x;
    }
    void setY(V y){
        this -> y = y;
    }
    
    T getX(){
        return x;
    }
    
    V getY(){
        return y;
    }
};

#include <iostream>
using namespace std;
int main(){
    
    pair2<pair2<int, double>, int> p3;
    p3.setY(100);
    
    pair2<int, double> p4;
    p4.setX(10);
    p4.setY(20.45);
    
    p3.setX(p4);
    
    cout << p3.getY() << endl;
    cout << p3.getX().getX() << endl;
    cout << p3.getX().getY() << endl;
    
    return 0;
    
}
