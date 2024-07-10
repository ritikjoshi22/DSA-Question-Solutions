#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* searchInBST(node* root, int key)
{
    if(root==NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    //root->data<key
    if(root->data < key){
        return searchInBST(root->right,key);
    }
    //root->data>key
    return searchInBST(root->left,key);
}

node* inorderSucc(node* root)
{
    node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

node* deleteInBst(node* root, int key)
{
    if(root->data > key){
        root->left = deleteInBst(root->left,key);
    }
    else if(root->data < key){
        root->right = deleteInBst(root->right,key);
    }
    else{
        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = inorderSucc(root);
        root->data = temp->data;
        root->right = deleteInBst(root->right,root->data);
    }
    return root;
}

void inorder(node* root)
{
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    if(searchInBST(root,7) == NULL){
        cout<<"Key doesn't exist"<<endl;
    }
    else{
        cout<<"Key exists"<<endl;
    }
    inorder(root);
    cout<<endl;
    deleteInBst(root,5);
    inorder(root);
    cout<<endl;
    return 0;
}
