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

bool isBST(node* root, node* min = NULL, node* max = NULL)
{
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }
    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return leftValid && rightValid;
}

int main()
{
    /*
    Second
                10
               /  \
              2    13
             / \  /  \
            1   3 11  15
    */

    node* root = new node(10);
    root->left = new node(2);
    root->right = new node(13);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(11);
    root->right->right = new node(15);

    if(isBST(root,NULL,NULL)){
        cout<<"First is Valid BST"<<endl;
    }
    else{
        cout<<"First is Invalid BST"<<endl;
    }

    /*
    Second
                10
               /  \
              7    9
             / \  /  \
            8   3 11  15
    */

    node* root1 = new node(10);
    root1->left = new node(7);
    root1->right = new node(9);
    root1->left->left = new node(8);
    root1->left->right = new node(3);
    root1->right->left = new node(11);
    root1->right->right = new node(15);

    if(isBST(root1,NULL,NULL)){
        cout<<"Second is Valid BST"<<endl;
    }
    else{
        cout<<"Second is Invalid BST"<<endl;
    }

    return 0;
}
