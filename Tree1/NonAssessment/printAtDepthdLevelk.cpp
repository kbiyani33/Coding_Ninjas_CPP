void printatLevelK(Node<int>* root, int k){
    
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root -> data << endl;
        return ;
    }
    
    for(int i=0; i < (root -> child).size(); i++){
        printatLevelK((root -> child)[i] , k-1);
    }
}
