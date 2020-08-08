Node* insertNodeRec(Node *head, int i, int data) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(i==0){
        Node *x = new Node(data);
        x -> next = head;
        return x;
    }
    
    if(head == NULL){
        return head;
    }
    
    Node *temp = head;
    head = head -> next;
    Node *b = insertNodeRec(head , i-1 , data);
    temp ->next = b;
    return temp;
    
}
