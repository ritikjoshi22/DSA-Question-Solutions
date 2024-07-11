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

node* constructBST(int preorder[], int* preorderIdx, int key, int min, int max, int n)
{
    if(*preorderIdx >= n){
        return NULL;
    }
    node* root = NULL;
    if(key>min && key<max){
        root = new node(key);
        *preorderIdx = *preorderIdx + 1;
        if(*preorderIdx < n){
            root->left = constructBST(preorder,preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if(*preorderIdx < n){
            root->right = constructBST(preorder,preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }
    return root;
}

void printPreorder(node* root)
{
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    /*
                10
               /  \
              2    13
             / \  /  \
            1   3 11  15
    */

    int preorder[] = {10,2,1,3,13,11,15};
    int n = 7;
    int preorderIdx = 0;
    node* root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    printPreorder(root);
    return 0;
}
