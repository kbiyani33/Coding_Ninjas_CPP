#include<iostream>
using namespace std;

//Linked Lists Basics
//Let's create the node to get an integer data point

class Node{
    public:
    int data;
    Node *next;
    
    
    Node(int data)//Whenever we access this class, we want to add an integer
    {
        this ->  data = data;
        next = NULL;
    }
    
    
};


void print(Node *head)//n contains the address of my head we can traverse with that element at once
    {
        Node *temp=head;
        while(temp != NULL){
            cout<<temp -> data<<" ";
            temp=temp -> next;//Now moving the head to the next node
        }
        temp=head;
        //cout<<head -> data;
        //NOTE:
        //When we exit the loop, head is Node, so even if we run the loop on the same linked list for printing again, the head in this local scope is still NULL. So even then it's printed only once.
        //But now we have lost the head of the LL, so we can never access it. So that's why we use a temp variable. It not only prevents us from losing our head, but also prints it as many times as we want.
    }

int main(){
    /*
    
    //Now we want to only create two nodes of my linkedlist
    /*
    //Remember, each element was represented by Node.
    //Consider a linkedlist like this:
    //1|200 2|380 3|NULL
    
    //i.e. the data points are 1, 2, 3 with the respective addresses of next element.
    //But one thing we should understand here is that each element is a NODE.
    //Thus, number of elements in the linked list = number of objects created to node class
    
    
    //LET'S MAKE STATIC OBJECT OF LINKEDLIST
    Node n1(1);
    //Since constructor is parameterized, thus we have to go with this
    //Now next will become Null; Now we will make a second node
    
    Node n2(2);
    
    //Now we have two nodes, which are not lnked as of now. Let's connect now
    //we have to set the next in n1 to address of n2
    
    n1.next = &n2;
    
    //First node in the linkedlist is called as Head
    //Last is Tail
    //We want to save the address of head in a variable for accessing. 
    //Since the address is of a node, the pointer is also of type node
    Node *head = &n1;
    
    //Now we will print the nodes of linked list with the help of head
    
    
    //MAKING THE NODES DYNAMICALLY
    Node *n3=new Node(10);
    Node *n4=new Node(20);
    Node *head=n3;
    n3 -> next = &n4;
    */
    //Now let's create  a linked list of 5 nodes
    //STATIC
    /*
    Node n1(1);
    Node *head=&n1;
    Node n2(2);
    Node n3(3);
    Node n4(40);
    Node n5(50);
    //CURRENTLY
    // 1|null 2|null 3|null 4|null 5|null
    
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    print(head);
    print(head);
    
    //Now, since I am passing the value, from main, another temporary copy of head is made, so calling it twice will actually print it twice. But running the loop twice there, only prints it once, since over there the head we are referring to is the local temporary copy head.
    */
    //DYNAMIC
    Node *n1=new Node(10);
    Node *n2=new Node(20);
    Node *n3=new Node(30);
    Node *n4=new Node(40);
    Node *n5=new Node(50);
    n1 -> next=n2;
    n2 -> next=n3;
    n3 -> next=n4;
    n4 -> next=n5;
    n5 -> next=NULL;
    
    Node *head = n1;
    print(head);
    //print(head);
    
    
    
}
