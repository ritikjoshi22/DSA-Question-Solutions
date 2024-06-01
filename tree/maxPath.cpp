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

int maxSumUtil(node* root, int &ans)
{
    if(root == NULL){
        return 0;
    }
    int left = maxSumUtil(root->left,ans);
    int right = maxSumUtil(root->right,ans);
    int nodeMax = max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans = max(nodeMax, ans);
    int singlePathSum = max(root->data, max(root->data+left,root->data+right));
    return singlePathSum;
}

int maxSum(node* root)
{
    int ans = INT_MIN;
    maxSumUtil(root,ans);
    return ans;
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

    cout<<"Max sum path from one node to another is:"<<maxSum(root)<<endl;
    return 0;
}
