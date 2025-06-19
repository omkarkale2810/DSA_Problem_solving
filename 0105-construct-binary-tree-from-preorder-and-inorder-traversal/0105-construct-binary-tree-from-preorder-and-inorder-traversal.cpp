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
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder , int instart ,int inend , int prestart , int preend){
        if(instart > inend){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);

        int i = instart;

        while(i <= inend){
            if(root->val == inorder[i]){
                break;
            }
            i++;
        }
        int lsize = i - instart;
        int rsize = inend - i;

        root->left = solve(inorder,preorder,instart,i-1,prestart+1,prestart+lsize);
        root->right = solve(inorder,preorder,i+1,inend,preend - rsize + 1,preend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return solve(inorder, preorder, 0, n - 1, 0, n - 1);
    }
};