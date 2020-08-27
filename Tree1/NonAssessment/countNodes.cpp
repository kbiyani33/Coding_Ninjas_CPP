template<typename T>
class Node{
    public:
    T data;
    vector <Node<T>*> child;
    
    Node(T data){
        
        this -> data = data;
        
    }
    
};

int count_Nodes(Node<int>* root){
    
    if(root == NULL){
        return 0;
    }
    
    
    if((root -> child.size()) == 0){
        return 1;
    }
    int smallans = 1;
    queue<Node<int>*> q;
    q.push(root);
    for(int i=0; i< (root -> child).size() ; i++){
        smallans += count_Nodes((root -> child)[i]);
    }
    return smallans;
}
