node *reverse_linked_list_rec(node *head)
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
