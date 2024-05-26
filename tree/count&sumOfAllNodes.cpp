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

int countNode(node* root)
{
    if(root == NULL) return 0;

    return countNode(root->left) + countNode(root->right)+1;
}

int sumOfNode(node* root)
{
    if(root == NULL) return 0;

    return sumOfNode(root->left) + sumOfNode(root->right) + root->data;
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

    cout<<"Number of node in the tree:"<<countNode(root)<<endl;
    cout<<"Sum of all node in the tree:"<<sumOfNode(root)<<endl;

    return 0;
}
