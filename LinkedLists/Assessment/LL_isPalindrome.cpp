Node* reverse(Node* head) {
    if(!head || !head->next) return head;
    
    Node* newHead = reverse(head->next);
    head->next->next = head;
    return newHead;
}

bool isPalindrome(Node* head)
{
    Node *temp = head;
    int count = 0;
    if(head == NULL || head -> next ==NULL)
        return true;
    while(temp != NULL) {
        count++;
        temp = temp -> next;
    }
    
    int mid = count  / 2;
    Node *temp2 = head;
    int i = 0;
    
    Node* prevMid = NULL;
    while(i < mid) {
        prevMid = temp2;
        temp2 = temp2->next;
        i++;
    }
    
    prevMid->next  = NULL;//making the first half linked list separate from second half(this gives us 1-2-3)
    Node *h2 = reverse(temp2);//reversing the second half(from 3-2-1 to 1-2-3)
    
    //the head of first half is still in head
    //the head of second half after reversal is in h2
    
    Node *temp3 = head;
    Node *temp4 = h2;
    while(temp3 != NULL && temp4 != NULL) {
        if(temp3 -> data != temp4 -> data) {
            return false;
        }
        else{
            temp3 = temp3 -> next;
            temp4 = temp4 -> next;
        }
    } 
    return true;
    
}
