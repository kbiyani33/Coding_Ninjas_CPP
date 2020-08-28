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

int height(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root == NULL){
        return 0;
    }
    
    if((root -> children).size() == 0){
        return 1;
    }
    
    int m = 0;
    for(int i =0; i < (root -> children).size() ; i++){
        m = max(m , height((root -> children)[i]));
    }
    return m+1;

}
