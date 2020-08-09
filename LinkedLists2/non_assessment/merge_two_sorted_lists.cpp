//MERGE SORTED LINKED LISTS FUNCTION
Node* mergeTwoLLs(Node *head1, Node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    Node *t1 = head1;
    Node *t2 = head2;
    Node *t;
    if(t1 == NULL){
        return t2;;
    }
    else if (t2 == NULL){
        return t1;
    }
    
    
    else if(t1 -> data <= t2 -> data){
        t = t1;
        t1 = t1 -> next ; 
    }
    
    else{
        t = t2;
        t2 = t2 -> next;
    }
    Node *x = t;//to be returned
    //t to be traversed
    while(t1 != NULL && t2 != NULL){
        if (t1 -> data <= t2 -> data){
            t -> next = t1;
            t = t -> next;
            t1 = t1 -> next;
        }
        else{
            t -> next = t2;
            t = t -> next;
            t2 = t2 -> next;
        }
    }
    while (t1 != NULL){
        t -> next = t1;
        t = t -> next;
        t1 = t1 ->next;
    }
    while(t2 != NULL){
        t -> next = t2;
        t = t -> next;
        t2 = t2 -> next;
    }
    
    return x;
    
}


//Class definition and main function
/*

#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
#include "Solution.h"

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}

*/
