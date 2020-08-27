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
#include<limits>
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root == NULL){
        return root;
    }
    
    TreeNode<int> *m = root;
    for(int i=0; i < root -> children.size(); i++){
        TreeNode<int>* temp = maxDataNode(root -> children[i]);
        if(temp -> data > m -> data)
            m = temp;
    }
    return m;

}
