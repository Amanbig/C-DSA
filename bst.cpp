#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left,*right;
    node(int data){
        left = NULL;
        right = NULL;
        this->data = data;
    }
};
class bst{
    public:
    void insert(node* &root,int data){
        if(root == NULL){
            root = new node(data);
        }
        else if(root->data > data){
            insert(root->left,data);
        }
        else if(root->data < data){
            insert(root->right,data);
        }
    }
    void inorder(node* &root){
        if(root != NULL){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
    void preorder(node* &root){
        if(root != NULL){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(node* &root){
        if(root != NULL){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<endl;
        }
    }
    void deletion(node* &root, int data) {
    if (root == NULL) {
        cout << "Tree is empty\n";
    } else if (root->data > data) {
        deletion(root->left, data);
    } else if (root->data < data) {
        deletion(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            cout << "Node deleted\n";
        } else if (root->left != NULL && root->right != NULL) {
            // Node with two children, find in-order successor and replace data
            node* successor = root->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            root->data = successor->data;
            deletion(root->right, successor->data);
        } else {
            // Node with one child
            node* temp = root;
            if (root->left != NULL) {
                root = root->left;
            } else {
                root = root->right;
            }
            delete temp;
            cout << "Node deleted\n";
        }
    }
}

};
int main(){
    bst b;
    node *root = NULL;
    b.insert(root,1);
    b.insert(root,5);
    b.insert(root,4);
    b.insert(root,6);
    b.insert(root,9);
    b.inorder(root);
    cout<<endl;
    b.deletion(root,6);
    b.inorder(root);
    cout<<endl;
    b.deletion(root,5);
    b.inorder(root);
    cout<<endl;
}