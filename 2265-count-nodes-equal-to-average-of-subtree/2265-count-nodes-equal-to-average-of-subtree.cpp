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
    // pair<sum,count> 
    int result;
    typedef pair<int,int> p;
    pair<int,int> solve(TreeNode* root){
        if( root == nullptr ){
            return {0,0};
        }
        p left = solve(root->left);
        p right = solve(root->right);

        int totalsum = left.first + right.first + root->val;
        int totalc =  left.second + right.second + 1;
        int avg = totalsum/totalc;
        if(avg == root->val){
            result++;
        }

        return {totalsum,totalc};
    }
    int averageOfSubtree(TreeNode* root) {
        p ans = solve(root);
        return result;
    }
};