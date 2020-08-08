Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    //let's find the tail first
    Node *tail = head;
    if (tail == NULL){
        return NULL;
    }
    int len = 1;
    while(tail -> next != NULL){
        len=len+1;
        tail = tail -> next;
    }
    //tail = tail -> next;
    if(n == 0 || n==len){
        return head;
    }
    else{
        
        
        //tail has the last element in the list
        int a = 1;
        Node *temp = head;
        while(a < len-n){
            temp = temp -> next;
            a+=1;
        }
        tail -> next = head;
        head = temp -> next;
        temp -> next = NULL;
        return head;
    }
}
