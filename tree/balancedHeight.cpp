#include <iostream>
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

int height(node* root)
{
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh,rh)+1;
}

bool isBalanced1(node* root)
{
    if(root == NULL){
        return true;
    }
    if(!isBalanced1(root->left)){
        return false;
    }
    if(!isBalanced1(root->right)){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}

bool isBalanced2(node* root, int* height)
{
    if(root == NULL){
        return true;
    }
    int lh=0,rh=0;
    if(!isBalanced2(root->left,&lh)){
        return false;
    }
    if(!isBalanced2(root->right,&rh)){
        return false;
    }
    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
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

    if(isBalanced1((root))){
        cout<<"Balanced tree"<<endl;
    }
    else{
        cout<<"Unbalanced tree"<<endl;
    }

    node* root2 = new node(1);
    root2->left = new node(2);
    root2->left->left = new node(3);
    int height = 0;
    if(isBalanced2(root2, &height)){
        cout<<"Balanced tree"<<endl;
    }
    else{
        cout<<"Unbalanced tree"<<endl;
    }
    return 0;
}
