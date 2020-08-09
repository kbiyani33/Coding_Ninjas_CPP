//ALGORITHM 1 - O(n^2) solution 			- 			VERY VERY BAD THAT JUST TO REVERSE WE ARE TO USE 0(n^2)

node *reverse_linked_list_rec1(node *head)
{
    //write your recursive code here
    node *temp = head;
    if(temp == NULL || temp -> next == NULL){
        return temp;
    }
    
    node * newHead = reverse_linked_list_rec(temp -> next);
    temp -> next =NULL;
    node *tail = newHead;
    while(tail ->next != NULL){
        tail = tail -> next;
    }
    
    tail -> next = temp;
    return newHead;
    
    
}

//ALGORITHM 2 : Let's have a better solution as described below. It's also known as Double Pointer Algorithm.

//Let's write a better solution and try and get it in O(n). 
//The idea is that instead of traversing to tail everytime, I'll return both head and tail.
class Pair{
    public:
    node *head;
    node *tail;
    
};

/*We have to return the object to the above defined class. 
If we ever want to return multiple values, return object of the class with al the values.
So, the new function I have to make is such that it returns the pair object

//This will have Time Complexity 0(n)
*/

Pair reverse_better(node *head){
    //return type is pair
    if(head == NULL || head -> next == NULL){
        Pair result;
        result.head = head;
        result.tail = head;
        
        return result;
    }
    
    Pair smallans = reverse_better(head -> next);
    smallans.tail ->next = head;
    head -> next = NULL;
    Pair finalans;
    finalans.head = smallans.head;
    finalans.tail = head;
    return finalans;
}


node* reverse_linked_list_rec(node* head){
    return reverse_better(head).head;
}



//CLASS DEFINITION AND MAIN
// Reverse Linked List  a. Using recursion  b. Without using recursion
/*
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
using namespace std;
#include "solution.h"
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* head=takeinput();
    head=reverse_linked_list_rec(head);
    print(head);
    return 0;
}
*/
