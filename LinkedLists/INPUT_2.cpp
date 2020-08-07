/*
Now, we have dealt with everything, but we need a better input function.
Important points:
1. While traversing the linkedlist, to print, use a temporary variable for
ensuring that we don't lose the head for improving some basic
functionalities in the future. 

2. The double pointer method for taking input has time complexity O(n) for n input nodes. 

3. After we take all the inputs, we will return the pointer to the head. Very Important.
*/
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int data){
        this -> data= data;
        this -> next= NULL;
    }
};

//GETTING LINKEDLIST INPUT, USING DOUBLE POINTER
Node* get_input(){
    int data=0;
    Node* head=NULL;
    Node* tail=NULL;
    cin>>data;
    while(data!=-1){
        Node *n=new Node(data);
        if(head==NULL){
            head=n;
            tail=n;
        }
        else{
            tail->next=n;
            tail=tail -> next;
        }
        
        cin>>data;
    }
    return head;
}

void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head=get_input();
    print(head);
}
