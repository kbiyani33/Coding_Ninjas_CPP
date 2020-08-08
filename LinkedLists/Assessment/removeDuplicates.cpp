Node *removeDuplicates(Node *head)
{
    //Write your code here
    Node *temp = head;
    if(temp == NULL){
        return head;
    }
    
    while(temp -> next != NULL){
        int d= temp -> data;
        Node *x = temp -> next;
        int d2 = x -> data;
        if(d == d2){
            temp -> next = x -> next;
            delete x;
        }
        else{
            temp = temp -> next;
        }
    }
    return head;
}
