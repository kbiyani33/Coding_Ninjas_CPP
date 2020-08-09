//Main Function of midpoint without getting the length of a linkedlist
node* midpoint_linkedlist(node *head)
{
    // Write your code here
    if(head == NULL || head -> next == NULL){
        return head;
    }
    node *fast = head; //we will move this by 2
    node *slow = head; //we will move this by 1
    
    while(fast -> next != NULL && fast -> next -> next != NULL ){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

//Class definition and main function
/*
//Find midpoint of a Linked List
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
    node*head=takeinput();
    node* mid=midpoint_linkedlist(head);
    cout<<mid->data;
    return 0;
}


*/
