Node *deleteNode(Node *head, int pos)
{
    //Write your code here
    Node *temp = head;
    if(pos == 0){
        temp = temp -> next;
        delete head;
        head = temp;
    }
    else{
        int a=1;
        Node *b1;
        //Node *b2;
        Node *temp = head;
        while(a<pos && temp != NULL){
            
            temp = temp -> next;
            a+=1;
        }
        if(temp != NULL && temp ->next != NULL){
            Node *aa = temp -> next;
            temp -> next = aa -> next;
            delete aa;
        }
    }
    return head;
}
