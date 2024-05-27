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

int calHeight(node* root)
{
    if(root == NULL){
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    return max(lHeight, rHeight) +1;
}

int calDiameter1(node* root)
{
    if(root == NULL){
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    int currHeight = lHeight+rHeight + 1;

    int lDiameter = calDiameter1(root->left);
    int rDiameter = calDiameter1(root->right);

    return max(currHeight, max(lDiameter, rDiameter));
}

int calDiameter2(node* root, int* height)
{
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calDiameter2(root->left, &lh);
    int rDiameter = calDiameter2(root->right, &rh);

    int currHeight = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currHeight, max(lDiameter, rDiameter));
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

    int height = 0;
    cout<<"Height of the tree:"<<calHeight(root)<<endl;
    cout<<"Diameter of the tree from method1:"<<calDiameter1(root)<<endl;
    cout<<"Diameter of the tree from method2:"<<calDiameter2(root, &height)<<endl;

    return 0;
}
