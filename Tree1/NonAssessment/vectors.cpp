//VECTORS

//What is a Vector ?
/*

It is a part of the Standard Template Library in C++. It allows us to
create an array, (even stack and a queue) dynamically. It's basically the inherent dynamic array.

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
   vector<int> v;
   v.push_back(10); // ............... (1)
   v.push_back(20);// ................ (2)
   v.push_back(30);// ................ (3)
   //PUSH BACK:
   /*
   
   Since we know that a Dynamic array will check for the current size and take care of the arguments such as capacity and it doubles the capacity of the array. 
   Similarly, push_back does the same.
   
  (1) adds 10 then (2) adds 20 in a subsequent memory space and so on.
  The capacity and everything is taken care of by push_back command.
  
  
  Also, push_back will actually ensure that the element, goes to the present last element which was added using the push_back only. For eg. if we write v[4] = 123, v[5] = 5., v.push_back(12) will actually make v[4] to be 12 and not 123.
  if we try to print we will get it.
  
  
  So square bracket should preferrably be used only for reading and updating.
  
   */
   
   cout << v[0] << " " << v[1] << " " << v[2] << endl ;
   
   v[2] = 120;
   v[4] = 150;
   cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
   
   //We have a couple more functions to take a look at:
   cout << v.size() << endl;
   cout << v.at(2) << endl; // This gives the element at index 2.
   /*
   
   at() is safer, since it will give an error if we try to access any element out of range, it thrws an error unlike "[]" which allows us to access any thing, with garbage value. so we will not get an error.
  
   */
   //Let's look at a few things:
   /* 1. How to iterate ?
      2. What is capacity and size ?
     */
    //ITERATION WAY 1
    cout << "NEW STUFF\n";
    vector<int> v1;
    
    for(int i = 0; i < 100 ; i++) {
        cout << "Size: " << v1.size () << endl;
        cout << "Cap: "  << v1.capacity() << endl ;  
        v1.push_back(i + 1);
    }
   
}
/*
OUTPUT:

10 20 30
10 20 120 0
3
120
NEW STUFF
Size: 0
Cap: 0
Size: 1
Cap: 1
Size: 2
Cap: 2
Size: 3
Cap: 4
Size: 4
Cap: 4
Size: 5
Cap: 8
Size: 6
Cap: 8
Size: 7
Cap: 8
Size: 8
Cap: 8
Size: 9
Cap: 16
Size: 10
Cap: 16
Size: 11
Cap: 16
Size: 12
Cap: 16
Size: 13
Cap: 16
Size: 14
Cap: 16
Size: 15
Cap: 16
Size: 16
Cap: 16
Size: 17
Cap: 32
Size: 18
Cap: 32
Size: 19
Cap: 32
Size: 20
Cap: 32
Size: 21
Cap: 32
Size: 22
Cap: 32
Size: 23
Cap: 32
Size: 24
Cap: 32
Size: 25
Cap: 32
Size: 26
Cap: 32
Size: 27
Cap: 32
Size: 28
Cap: 32
Size: 29
Cap: 32
Size: 30
Cap: 32
Size: 31
Cap: 32
Size: 32
Cap: 32
Size: 33
Cap: 64
Size: 34
Cap: 64
Size: 35
Cap: 64
Size: 36
Cap: 64
Size: 37
Cap: 64
Size: 38
Cap: 64
Size: 39
Cap: 64
Size: 40
Cap: 64
Size: 41
Cap: 64
Size: 42
Cap: 64
Size: 43
Cap: 64
Size: 44
Cap: 64
Size: 45
Cap: 64
Size: 46
Cap: 64
Size: 47
Cap: 64
Size: 48
Cap: 64
Size: 49
Cap: 64
Size: 50
Cap: 64
Size: 51
Cap: 64
Size: 52
Cap: 64
Size: 53
Cap: 64
Size: 54
Cap: 64
Size: 55
Cap: 64
Size: 56
Cap: 64
Size: 57
Cap: 64
Size: 58
Cap: 64
Size: 59
Cap: 64
Size: 60
Cap: 64
Size: 61
Cap: 64
Size: 62
Cap: 64
Size: 63
Cap: 64
Size: 64
Cap: 64
Size: 65
Cap: 128
Size: 66
Cap: 128
Size: 67
Cap: 128
Size: 68
Cap: 128
Size: 69
Cap: 128
Size: 70
Cap: 128
Size: 71
Cap: 128
Size: 72
Cap: 128
Size: 73
Cap: 128
Size: 74
Cap: 128
Size: 75
Cap: 128
Size: 76
Cap: 128
Size: 77
Cap: 128
Size: 78
Cap: 128
Size: 79
Cap: 128
Size: 80
Cap: 128
Size: 81
Cap: 128
Size: 82
Cap: 128
Size: 83
Cap: 128
Size: 84
Cap: 128
Size: 85
Cap: 128
Size: 86
Cap: 128
Size: 87
Cap: 128
Size: 88
Cap: 128
Size: 89
Cap: 128
Size: 90
Cap: 128
Size: 91
Cap: 128
Size: 92
Cap: 128
Size: 93
Cap: 128
Size: 94
Cap: 128
Size: 95
Cap: 128
Size: 96
Cap: 128
Size: 97
Cap: 128
Size: 98
Cap: 128
Size: 99
Cap: 128



*/
