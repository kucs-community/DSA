//Binary Search Tree
#include<iostream>

using namespace std;

class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node(int v){
            left=right=NULL;
            val = v;
        };
};

class Bst {
    private:
        Node* head;
    public:
        Bst(){head=NULL;}
        void insertNode(int);
        void deleteNode(int);
        void addNode(Node*,int);
        bool search(int);
        bool searchNode(Node*,int);
        void inOrder();
        void inOrderTraversal(Node*);
        void deleteElement(Node*,Node*,int);
        int findMinimum(Node*);
};

void Bst::insertNode(int val){

    Node* node = head;

    addNode(node,val);
}

void Bst::addNode(Node* node, int val){
    
    if(node == NULL){
        head = new Node(val);
        return;
    }

    if(node->val > val){
        if(node->left == NULL){
            node->left = new Node(val);
            return;
        }

        addNode(node->left, val);
    }
    else{
        if(node->right == NULL){
            node->right = new Node(val);
            return;
        }

        addNode(node->right, val);
    }
}

void Bst::inOrder(){

    Node* node = head;

    inOrderTraversal(node);
    cout<<endl;   
}

void Bst::inOrderTraversal(Node* node){

    if(node == NULL) return;
    
    inOrderTraversal(node->left);

    cout<<node->val<<" ";

    inOrderTraversal(node->right);
}

bool Bst::search(int val){

    Node* node = head;

    return searchNode(node, val);
}

bool Bst::searchNode(Node* node, int val){

    if(node == NULL)
        return false;
    
    if(val < node->val){
        return searchNode(node->left, val);
    }
    else if(val > node->val){
        return searchNode(node->right, val);
    }
    else{
        return true;
    }
    cout<<"End"<<endl;
}

void Bst::deleteNode(int val) {
    Node* node = head;

    deleteElement(node,node, val);
}

/*------
    function to delete a node from bst..there are three scenarios
    1. it is a leaf node
    2. it has only one child
    3. it has two children
-------*/
void Bst::deleteElement(Node* node, Node* parent, int val){
    
    if(node == NULL)
        return;

    if(val < node->val){
        deleteElement(node->left, node, val);
    }
    else if(val > node->val){
        deleteElement(node->right, node, val);
    }
    else{
        //scenario 1
        if(node->left == NULL and node->right == NULL){

            //the leaf node could be left or right child
            if(parent->left == node){

                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
            delete node;
        }
        else if (node->left != NULL and node->right == NULL) {

            if(parent->left == node){

                parent->left = node->left;
            }
            else{

                parent->right = node->left;
            }
            delete node;
        }
        else if(node->right != NULL and node->left == NULL){

            if(parent->left == node){
                
                parent->left = node->right;
            }
            else{

                parent->right = node->right;
            }
            delete node;
        }
        else if(node->left != NULL and node->right != NULL){

            node->val = findMinimum(node->right);
            deleteElement(node->right, node, node->val); //delete the minimum value in the right subtree
        }
    }
}

//function to find minimum value in a subtree should not be used to find minimum in bst
//node can not be null
int Bst::findMinimum(Node* node){

    while(true){
        if(node->left)
            node = node->left;
        else
            break;
    }

    return node->val;
}

int main(){

    Bst b;
    b.insertNode(34);
    b.insertNode(48);
    b.insertNode(10);
    b.insertNode(42);
    b.insertNode(17);
    
    b.inOrder();
    
    cout<<b.search(34)<<endl;

    b.deleteNode(34);

    b.inOrder();

    return 0;
}
