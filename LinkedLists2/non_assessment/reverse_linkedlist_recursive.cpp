//ALGORITHM 1 - O(n^2) solution 			- 			VERY VERY BAD THAT JUST TO REVERSE WE ARE TO USE 0(n^2)

node *reverse_linked_list_rec1(node *head)
{
    //write your recursive code here
    node *temp = head;
    if(temp == NULL || temp -> next == NULL){
        return temp;
    }
    
    node * newHead = reverse_linked_list_rec1(temp -> next);
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

//Time Complexity  O(n)
//Space Complexity O(n)
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


node* reverse_linked_list_rec2(node* head){
    return reverse_better(head).head;
}

//ALGORITHM 3 - To prove why we are really stupid xD.
//Time Complexity O(n)
//Space Complexity O(1)
/*

Consider the linked list, 1 -> 2 -> 3 -> 4 -> 5 -> NULL
head = &1
when we call the recursive function on head -> next , we get smallans = 5 and the returned linked list is:
5 -> 4 -> 3 -> 2 -> NULL
We have been trying to simply get the tail of returned linked list and then attach the passed head to this tail.
But in the original list, the head is 1 and the recursively returned linked list is having tail 2
Isn't tail of returned list, still connected to the head of input list, i.e. 1?
so we can maike the next of head as the tail and attach the head to that tail
node *tail = head -> next
tail -> next = head
head -> next = NULL
Now we will return 5 -> 4 -> 3 -> 2 -> 1 -> null 

*/
node *reverse_linked_list_rec3(node *head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    node *small = reverse_linked_list_rec3(head -> next);
    node *tail = head -> next;
    tail -> next = head;
    head -> next = NULL;
    return small;
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
