// Ques:  Do a spiral order traversal  traversal of a binary tree
// https://www.techiedelight.com/spiral-order-traversal-binary-tree/


#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public: 
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x)
        {
            val=x;
            left=nullptr;
            right=nullptr;
        }
};

void printArray(vector<int> v, bool c)
{
    if(c) 
        for(auto x: v) cout<< x <<" ";
    else 
    {
        for(int j=v.size()-1; j>=0; j--)
            cout<< v[j]<< " ";
    }
}
void spiralTraversal(TreeNode* root)
{
    queue<TreeNode*> q;
    bool counter=true;
    q.push(root);
    while(!q.empty())
    {
        vector<int> v;
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        printArray(v,counter);
        counter=!counter;
    }
}
void inorder(TreeNode* root)
{
    if(root == nullptr) return;
    inorder(root->left);
    cout<< root->val;
    inorder(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    spiralTraversal(root);
}
