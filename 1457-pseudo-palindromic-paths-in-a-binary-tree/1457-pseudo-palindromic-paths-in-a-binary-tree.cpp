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
    int result = 0;
    bool checkpsudopalindrome(vector<int>& hash){
        int oddfreq =0;
        for(int i = 0 ; i < 10 ; i++){
            if(hash[i]&1!=0){
                oddfreq++;
            }
        }
        return oddfreq<=1;
    }
    void solve(TreeNode* root , vector<int>& hash){
        if(root == nullptr){
            return;
        }
        hash[root->val]++;
        if(root->left == nullptr && root->right == nullptr){
            if(checkpsudopalindrome(hash)){
                result++;
            }
        }
        solve(root->left , hash);
        solve(root->right , hash);
        hash[root->val]--;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> hash(10,0);
        solve(root,hash);
        return result;
    }
};