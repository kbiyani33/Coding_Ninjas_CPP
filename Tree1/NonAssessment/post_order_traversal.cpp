// Following is the given Tree node structure.
/**************
 template <typename T>
 class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;
 
        TreeNode(T data) {
            this->data = data;
        }
 
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
 };
***************/

void postOrder(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output in specified format.
     */
    if(root == NULL){
        return;
    }
    
    if((root -> children).size() == 0){
        cout << root -> data << " ";
        return;
    }
    
    for(int i = 0 ; i < (root -> children).size(); i++){
        postOrder((root -> children)[i]);
    }
    cout << root -> data << " ";

}
