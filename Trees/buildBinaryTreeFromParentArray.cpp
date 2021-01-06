#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data)
        {
            val=data;
            left=nullptr;
            right=nullptr;
        }
};

void inorder(TreeNode* root)
{
    if(root == nullptr) return;
    inorder(root->left);
    cout<< root->val <<" ";
    inorder(root->right);
}

TreeNode* buildBinaryTree(vector<int> parentArr, vector<int> indexArr)
{
    map<int, TreeNode*> mp;

    for(auto x: indexArr)
    {
        TreeNode* tmp = new TreeNode(x);
        mp[x]=tmp;
    }

    TreeNode* root = nullptr;
    for(int i=0; i<parentArr.size(); i++)
    {
        if(parentArr[i] == -1) 
            root=mp[indexArr[i]];
        else
        {
            TreeNode* tmp = mp[parentArr[i]];
            if(tmp->left)
                tmp->right = mp[indexArr[i]];
            else 
                tmp->left = mp[indexArr[i]];
        }
        
    }
    return root;
}
int main()
{
    vector<int> parentArr = {-1, 0, 0, 1, 2, 2, 4, 4};
    vector<int> indexArr = {0, 1, 2, 3, 4, 5, 6, 7};
    
    inorder(buildBinaryTree(parentArr, indexArr));
    return 0;
}