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

void rightView(node* root)
{
    if(root == NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            node* newNode = q.front();
            q.pop();
            if(i == n-1){
                cout<<newNode->data<<" ";
            }
            if(newNode->left != NULL){
            q.push(newNode->left);
            }
            if(newNode->right != NULL){
                q.push(newNode->right);
            }
        }
    }
}

void leftView(node* root)
{
    if(root == NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            node* newNode = q.front();
            q.pop();
            if(i == 0){
                cout<<newNode->data<<" ";
            }
            if(newNode->left != NULL){
            q.push(newNode->left);
            }
            if(newNode->right != NULL){
                q.push(newNode->right);
            }
        }
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

    cout<<"The right view of the tree: ";
    rightView(root);
    cout<<endl;
    cout<<"The left view of the tree: ";
    leftView(root);
    cout<<endl;
    return 0;
}
