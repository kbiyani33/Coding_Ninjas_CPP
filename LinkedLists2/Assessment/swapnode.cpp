node* swap_nodes(node *head,int i,int j)
{
    
    if(i == j){
        return NULL;
    }
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    int x = i, y = j;
    i = min(x,y);
    j = max(x,y);
    
    //now i is smaller, and j is bigger
    node *temp = head;
    int count = 0;
    while(temp != NULL){
        count += 1;
        temp = temp -> next ; 
    }
    
    if(j >= count){
        return NULL;
    }
    node *prei = head;
    node *prej = head;
    node *curri , *currj ; 
    int a=0;
    
    
    while(a < j-1){
        prej = prej -> next;
        a = a+1;
    }
    currj = prej -> next;
    node* nextj = currj -> next;
    a = 0;
    if(i == 0){
        curri = head;
        prej -> next = curri;
        currj -> next = head -> next;
        curri -> next = nextj;
        head = currj;
        //prei = NULL;
    }
    else if(i>0){
    	
    	while(a < i-1){
        	prei = prei -> next;
     		a = a+1;
    	}
    	curri = prei -> next;
        
    	if(j > i+1){
            node* nexti = curri -> next;
    		prei -> next = currj;
    		prej -> next = curri;
    		currj -> next = nexti;
    		curri -> next = nextj;
        }
        else{
            prei -> next = currj;
            currj -> next = curri;
            curri -> next = nextj;
        }
        
    }
    return head;
}
