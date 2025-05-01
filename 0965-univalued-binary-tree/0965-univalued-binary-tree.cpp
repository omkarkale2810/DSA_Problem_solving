/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    unordered_set<int>st;
    void inorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        inorder(root->left );
        st.insert(root->val);
        inorder(root->right );
    }
    bool isUnivalTree(TreeNode* root) {
        int xorr = 0;
        inorder(root);
        return st.size()==1;
    }
};