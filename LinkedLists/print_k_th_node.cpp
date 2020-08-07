int length_of_LL(Node *head){
    if(head!=NULL){
    	int l=1;
    	Node* temp=head;
    	while(temp -> next !=NULL){
        	l+=1;
        	temp = temp->next;
    	}
    return l;
    }
    else{
        return 0;
    }
}
void printIthNode(Node *head, int i)
{
    //Write your code here
    //getting the length
    int len=length_of_LL(head);
    if(i>=len){
        return;
    }
    else{
        int a=i;
        Node *temp = head;
        while(a != 0){
            temp = temp -> next;
            a-=1;
        }
        cout<<temp -> data;
    }
}
