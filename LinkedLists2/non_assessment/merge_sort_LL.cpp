//Merge_Sort Function

node* merge(node *head1, node *head2){
    node *t1 = head1;
    node *t2 = head2;
    
    node *t;
    if(t1 == NULL){
        return t2;
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
    node *x = t;//to be returned
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

node* mergeSort(node *head) {
    //write your code here
    
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    node *fast = head;
    node *mid = head;
    
    while(fast -> next != NULL && fast -> next -> next !=NULL){
        mid = mid -> next;
        fast = fast -> next -> next;
    }
    
    //midpoint is in mid
    node *head1 = head;//
    node *head2 = mid -> next;//in 1-2-3-4, mid will be at 2, so second half from 3.
    mid -> next = NULL; 
    /*
    This separates, 1-2-3-4 into 1-2 with 1 in head1 and 3-4 with 3 in head2
    Now we simply call merge of these two separate linked lists
    */
    node *l1 = mergeSort(head1);
    node *r1 = mergeSort(head2);
    node *sortedhead = merge(l1, r1);
    return sortedhead;
}



//CLASS DEFINITION AND MAIN FUNCTION
/*

//merge sort recursive
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
int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}



*/
