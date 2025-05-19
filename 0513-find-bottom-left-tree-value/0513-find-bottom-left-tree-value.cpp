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
    void dfs(TreeNode* root , int depth , int& result , int& maxdepth){
        if(root == nullptr){
            return;
        }
        if(maxdepth < depth){
            maxdepth = depth;
            result = root->val;
        }
        dfs(root->left , depth+1 , result , maxdepth);
        dfs(root->right , depth+1 , result , maxdepth);
    }
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0;
        int result = -1;
        int maxdepth = -1;
        dfs(root , depth , result , maxdepth);
        return result;
    }
};