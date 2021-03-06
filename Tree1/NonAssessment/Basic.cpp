#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    vector <Node<T>*> child;
    
    Node(T data){
        
        this -> data = data;
        
    }
    
};
template<typename T>
void printTree(Node<T> *root){
    //95% of all tree functions are based on recursion.
    //Edge case
    if(root == NULL){
        return ;
    }
    
    cout << root -> data << ":";
    for(int i = 0 ; i < (root -> child).size() ; i++){
        cout << (root -> child).at(i) -> data << ",";
    }
    cout << endl;
    for(int i = 0 ; i < (root -> child).size() ; i++){
        printTree((root -> child).at(i));
    }
    /*
    POINTERS:
    1. When we use recursion with generic trees, a single node acts as a base case in case it has no children.
    
    2.
    for(int i = 0 ; i < (root -> child).size() ; i++){
        printTree((root -> child).at(i));
    }
    The above for loop alone prints 
    1
    2
    3
    Since this output could correspond to two different trees:
    
    we need a better way of printing. Something like:
    1:2,3
    2:
    3:
    
    Let's make the necessary changes.
    */
}

//Let's develop an automated input function and try and return the root
//template<typename T>
Node<int>* takeInput(){
    int d; 
    cout << "ENTER DATA" << endl ;
    cin >> d ;
    Node<int>* newNode = new Node<int>(d);
    int n = 0;
    cout << "Enter the number of children" << endl;
    cin >> n ;
    for(int i =0; i < n; i++){
        Node<int>* x = takeInput();
        (newNode -> child).push_back(x);
    }
    return newNode ;
}
Node<int>* takeInputLevel(){
    int d;
    //In this, we will use queue
    queue<Node<int>*> q;//because we not only want the data, we also want to attach it to the root.
    cout << "ENTER DATA OF ROOT" << endl ;
    cin >> d ;
    Node<int>* root = new Node<int>(d) ;
    q.push(root);
    while(!q.empty()){
        Node<int>* front = q.front();
        q.pop();
        cout <<"The number of children of "<<front -> data << endl;
        int num;
        cin >> num;
        for(int i = 0; i<num; i++){
            int currentchild;
            cout <<"Enter "<< i <<"th child of " << front -> data << endl;
            cin >> currentchild;
            Node<int>* b = new Node<int>(currentchild); //We don't use static since it gets deallocated after getting out of the loop itself.
            
            (front -> child).push_back(b);
            q.push(b);
            
        }
        
    }
    return root;
    
}
int main()
{
    /*
    Node<int> *root = new Node<int>(1);
    Node<int> *c1 = new Node<int>(2);
    Node<int> *c2 = new Node<int>(3);
   
    (root -> child).push_back(c1);
    (root -> child).push_back(c2);
    */
    Node<int> *root = takeInput();
    printTree(root);
   /* Desired tree.
   
                (1) Root
            /       \
        /               \
    (2)                     (3)
   
   */
   return 0;
   
}
