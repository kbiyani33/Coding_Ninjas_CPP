// Following is the given TreeNode structure.
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


void printLevelWise(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
    /*
    queue <TreeNode<int>*> pending;
    pending.push(root);
    while( pending.size() != 0 ){
        cout<<pending.front() -> data<<":";
        for(int i = 0; i < pending.front() -> children.size(); i++){
            cout<< pending.front() -> children[i] -> data;
            pending.push(pending.front()->children[i]);
            if(i<pending.front()->children.size()-1){
                cout<<",";
            }
        }
        cout<<endl;
       10 3 20 30 40 2 40 50 0 0 0 0  pending.pop();
    }
    */
    if(root == NULL){
        return;
    }
    
    queue<TreeNode<int>*> pending;
    pending.push(root);
    
    while(pending.size() != 0){
        TreeNode<int>* front = pending.front();        
        cout << front -> data << ":";
        for(int i = 0; i < (front -> children).size() ; i++){
            pending.push((front -> children)[i]);
            cout << (front -> children)[i] -> data;
            if(i != (front -> children).size() - 1){
                cout << ",";
            }
        }
        cout << endl;
        pending.pop();
    }
    
}
