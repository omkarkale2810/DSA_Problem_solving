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
    int solve(TreeNode* root, TreeNode* parent){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            if( parent != nullptr && parent->left == root){
                return root->val;
            }
        }
        int left = solve(root->left , root);
        int right = solve(root->right, root);

        return left + right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr){
            return 0;
        }
        return solve(root , nullptr);
    }
};