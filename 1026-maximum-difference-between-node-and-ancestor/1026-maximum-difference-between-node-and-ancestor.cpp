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
    int solve(TreeNode* root , int maxp , int minp){
        if(root == nullptr){
            return abs(maxp-minp);
        }
        minp = min(minp , root->val);
        maxp = max(maxp , root->val);
        
        int l = solve(root->left , maxp , minp);
        int r = solve(root->right , maxp , minp);

        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = solve(root,INT_MIN , INT_MAX);
        return ans;
    }
};