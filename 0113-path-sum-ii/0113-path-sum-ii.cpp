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
    vector<vector<int>> ans;
    void solve(TreeNode* root , vector<int> temp , int sum , int target){
        if(root == nullptr){
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(target == sum){
                ans.push_back(temp);
            }
            return;
        }
        solve(root->left , temp , sum , target);
        
        solve(root->right , temp , sum , target);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        solve(root ,temp , sum, targetSum);
        return ans;    
    }
};