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
    string result = "";
    void dfs(TreeNode* root , string s){
        if(root == nullptr){
            return;
        }
        char ch = char('a' + root->val);
        s = ch + s; 
        if(root->left == nullptr && root->right == nullptr){
            if(result == "" || result > s){
                result = s;
            }
        }
        dfs(root->left , s);
        dfs(root->right , s);
        s = s.substr(1,s.length());
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return result;
    }
};