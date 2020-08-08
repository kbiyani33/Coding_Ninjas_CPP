Node* deleteNodeRec(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(i == 0){
        Node *temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    
    if(head == NULL || head -> next ==NULL){//we have to make sure that i node is not just one after the last node
        return head;
    }
    
    Node *a = head;
    head = head -> next;
    Node *b = deleteNodeRec(head , i-1);
    a -> next = b;
    return a;
    
}

