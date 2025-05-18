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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue< pair<TreeNode*,ll> > q;
        q.push({root,0});
        ll width = 1;
        while(!q.empty()){
            pair<TreeNode* , ll> fro = q.front();
            pair<TreeNode* , ll> back = q.back();
            width = max(width,back.second-fro.second+1);
            int n = q.size();
            while(n--){
                pair<TreeNode* , ll> curr = q.front();
                q.pop();
                if(curr.first->left!=nullptr){
                    q.push({curr.first->left , curr.second*2+1});
                }
                if(curr.first->right!=nullptr)
                    q.push({curr.first->right , curr.second*2+2});
            }
        }
        return width;
    }
};