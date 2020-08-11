node* kReverse(node*head,int n)
{
    //write your code here
    // Let us solve this problem recursively
    if(head == NULL || n<=1){
        return head;
    }
    node *prev=head, *curr=prev -> next, *next;
	int i=1;
    prev->next =NULL;
    while(curr!=NULL && i<n)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    head->next = kReverse(curr, n);
    return prev;
}
