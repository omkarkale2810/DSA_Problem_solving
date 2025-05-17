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
    string string_subtree_check(TreeNode* root, unordered_map<string,int>& mp ,  vector<TreeNode*>& ans){
        if(root==NULL){
            return "N";
        }
        string s = to_string(root->val)+","+string_subtree_check(root->left , mp , ans)+","+string_subtree_check(root->right , mp , ans);
        if(mp[s]==1){
            ans.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> ans;
        string_subtree_check(root , mp , ans);
        return ans;
    }
};