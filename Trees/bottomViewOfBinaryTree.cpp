// Print the bottom view of the Tree. If two nodes or more nodes are present at same horizontal distance on same level print the first node of the level. 


#include<bits/stdc++.h>
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

void bottomView(TreeNode* root, int dis, int level, map<int, pair<int,int>> &mp)
{
    if(root == nullptr) return;
    if(level > mp[dis].second)
        mp[dis] = {root->val,level};
    bottomView(root->left, dis-1,level+1,mp);
    bottomView(root->right, dis+1,level+1,mp);
}


void printBottomView(TreeNode* root)
{
    // create an empty map where
    // key -> relative horizontal distance of the node from root node and
    // value -> pair containing node's value and its level
    map<int, pair<int,int>> mp; 
    bottomView(root,0,0,mp);

    for(auto x:mp)
        cout << x.second.first <<" "; 
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(100);
    root->left->right = new TreeNode(200);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8); 

    printBottomView(root);
    return 0;
}