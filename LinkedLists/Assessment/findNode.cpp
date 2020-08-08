int findNode(Node *head, int n)
{
    //Write your code here
    Node *temp = head;
    int a=0;
    int flag =0 ;
    while(temp != NULL){
        if(temp -> data == n){
            flag = 1;
            break;
        }
        temp = temp -> next;
        a=a+1;
    }
    if(flag == 1){
        return a;
    }
    else{
        return -1;
    }
}
