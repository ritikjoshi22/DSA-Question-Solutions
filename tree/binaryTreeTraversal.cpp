#include<iostream>

using namespace std;

class node
{
public:
    int data;
    node* right;
    node* left;

    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

void preoder(node* root)
{
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preoder(root->left);
    preoder(root->right);
}

void inorder(node* root)
{
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root)
{
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preoder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}