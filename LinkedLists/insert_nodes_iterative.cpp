Node* insert(Node *head , int i, int d){
    //insert node at position i, i is an index.
    Node *newnode = new Node(d);
    //int a=0;
    Node *temp=head;
    if(i==0){
        //that is we are inserting at the first element, the head changes
        newnode -> next = head;
        head = newnode;
    }
    // Now we will travel to position i. 
    else
    {
        int a=1;//reason, we take 1 is because the 0th is already taken into account
        while(a<i){
            temp = temp -> next;
            a+=1;
        }
    //Now we will be getting the node address of node one before position i in temp
    //Now next of temp is the newnode and next of new node is the 
        Node * ip=temp -> next;
        temp -> next = newnode;
        newnode -> next = ip;
    }
    return head;
}
