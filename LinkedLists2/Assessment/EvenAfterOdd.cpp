node* arrange_LinkedList(node* head)
{
    //write your code here
    node *temp = head;
    node *temp2 = head;
    if(temp == NULL || temp -> next == NULL){
        return head;
    }

    node *odd ;
    node *oddtail;
    node *even ;
    node *eventail ;
    int flagodd = 0;
    int flageven = 0;
    //First let's get the first even and first odd values
    while(temp -> next != NULL){
        if((temp -> data)% 2 == 1){
            odd = new node(temp -> data);
            flagodd = 1;
            oddtail = odd;
            temp = temp ->next;
            break;
        }
        temp = temp -> next;
    }
    while(temp2 -> next != NULL){
        if((temp2 -> data)% 2 == 0){
            even = new node(temp2 -> data);
            eventail = even;
            flageven = 1;
            temp2 = temp2 ->next;
            break;
        }
        temp2 = temp2 -> next;
    }
    if(flagodd != 0){
    while(temp != NULL){
        if(temp -> data %2 == 1){
            oddtail -> next = new node(temp -> data);
            oddtail = oddtail -> next;
        }
        temp = temp -> next;
    }
    }
    if(flageven != 0){
    while(temp2 != NULL){
        if(temp2 -> data %2 == 0){
            eventail -> next = new node(temp2 -> data);
            eventail = eventail -> next;
        }
        temp2 = temp2 -> next;
    }
    }
    if(flagodd == 1 && flageven == 1){
    	oddtail -> next = even;
    	eventail -> next = NULL;
        return odd;
    }
    else if(flagodd == 1){
        oddtail ->next = NULL;
        return odd;
        
    }
    else{
        eventail -> next = NULL;
        return even;
    }

    
}
