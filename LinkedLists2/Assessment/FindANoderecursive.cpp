int indexOfNRecursive(Node *head, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    Node *temp = head ; 
    if((temp == NULL) || (temp -> next == NULL && temp -> data != n)){
        return -1;
    }
    
    
    //int i = 1;
    if (temp -> data == n){
        return 0;
    }
    temp = temp -> next;
    int small_output = indexOfNRecursive(temp , n);
    if(small_output == -1){
        return -1;
    }
    else{
        return 1+small_output;
    }
}
