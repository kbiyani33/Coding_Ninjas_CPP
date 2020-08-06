#include<iostream>
using namespace std;

//Linked Lists Basics
//Let's create the node to get an integer data point

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//now let's write a function to create as many nodes as the user wants in the linked list and not making them together like one after the other. 
// How do we make it?
//Get the input from user and check if it matches the exit condition, if it does, exit and return the head of the linked list

Node* create_nodes(){
    int data=0;
    cin>>data;
    Node *head=NULL;
    while(data!=-1){
        //Node n(data);//Making this like this will result in our subsequent nodes being deallocated, once we leave this loop, so we should create the object dynamically
        Node *n=new Node(data);
        if(head==NULL){
            head=n;
        }
        else{
            Node *temp=head;
            while(temp -> next != NULL){
                temp=temp->next;
            }
            temp -> next = n;
        }
        
        cin>>data;
    }
    return head;
}

int main(){

    Node *head = create_nodes();
    print(head);
}
