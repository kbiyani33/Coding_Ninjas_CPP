//OUR FUNCTION
template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
        this -> size = 0;
        this -> head = NULL;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    void push(T element) {
        Node<T> *n = new Node<T>(element);
        n -> next = head;
        head = n;
        size += 1;
    }
    
    T pop() {
        // Return 0 if stack is empty. Don't display any other message
        if(isEmpty()){
            return 0;
        }
        Node<T> *temp = head;
        head = head -> next;
        size -= 1;
        return temp -> data;
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if(isEmpty()){
            return 0;
        }
        return head -> data;
    }
    
  
    
};


//STACK CLASS
/*
#include "Stack.h"
    int main() {
        
        Stack<int> st;
        
        int choice;
        cin >> choice;
        int input;
        
        while (choice !=-1) {
            if(choice == 1) {
                cin >> input;
                st.push(input);
            }
            else if(choice == 2) {
                int ans = st.pop();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 3) {
                int ans = st.top();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 4) {
                cout << st.getSize() << endl;
            }
            else if(choice == 5) {
                cout << st.isEmpty() << endl;
            }
            cin >> choice;
        }
    
    } 
*/

//NODE CLASS AND MAIN CLASS
/*
#include<iostream>
using namespace std;


template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

#include "Stack.h"
    int main() {
        
        Stack<int> st;
        
        int choice;
        cin >> choice;
        int input;
        
        while (choice !=-1) {
            if(choice == 1) {
                cin >> input;
                st.push(input);
            }
            else if(choice == 2) {
                int ans = st.pop();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 3) {
                int ans = st.top();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 4) {
                cout << st.getSize() << endl;
            }
            else if(choice == 5) {
		if(st.isEmpty()){
                	cout << "true" << endl;
		}else{
			cout << "false" << endl;
		}
            }
            cin >> choice;
        }
    
    }

*/
