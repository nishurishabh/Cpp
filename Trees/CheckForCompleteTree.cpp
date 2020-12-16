// Given a tree, check wether the tree is complete or not.

// https://www.techiedelight.com/check-given-binary-tree-complete-binary-tree-not/


#include <bits/stdc++.h>

using namespace std;

class TreeNode {
    public: 
        int val;
        TreeNode* left;
        TreeNode* right;
    TreeNode(int val)
    {
        this->val=val;
        this->left=this->right=nullptr;
    }
};

void inorder(TreeNode* root)
{
    if(root == nullptr) return;
    inorder(root->left);
    cout<< root->val <<" ";
    inorder(root->right);
}
int sizeOfTree(TreeNode* root) {
    if(root == nullptr) return 0;
    return 1+sizeOfTree(root->left)+sizeOfTree(root->right); 
}

void inorderUtil(TreeNode* root, vector<bool> &A, int i)
{
    if(root == nullptr) return;
    inorderUtil(root->left,A,2*i+1);
    A[i]=true;
    inorderUtil(root->right,A,2*i+2);
}

bool isComplete(TreeNode* root, int size)
{
    vector<bool> A(size, false);
    inorderUtil(root, A, 0);
    for(int i=0; i<size; i++)
    {
        if(!A[i]) return false;
    }
    return true;
}

int main()
{
    TreeNode* root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->right->left = new TreeNode(9);

    cout<< isComplete(root, sizeOfTree(root));
}

// A complete tree has all levels except the last level as completely filled. And the last level has nodes from right to left

// Tree: 1 2 3 4 5 6 7 8 null 9       