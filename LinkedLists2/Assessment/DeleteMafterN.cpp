node* skipMdeleteN(node  *head, int m, int n) {
    // Write your code here
    
    if(m == 0){
        return NULL;
    }
 
    else if(n == 0){
        return head;
    }
    
    else if(head == NULL || head -> next == NULL){
        return head;
    }
    
    
    node *curr = head;
    node *curr2;
    while(curr != NULL){
        int i = 1,j = 1;//i for M, j for N
        while(i < m && curr != NULL && curr -> next != NULL){
            curr = curr -> next;
            i+=1;
        }
        curr2 = curr;
        if(curr -> next == NULL){
            break;
        }
        
        while(j <= n && curr != NULL && curr -> next != NULL){
            curr = curr -> next;
            j+=1;
        }
        curr2 -> next = curr -> next;
        curr = curr -> next;
        
    }
    return head;
    
}
