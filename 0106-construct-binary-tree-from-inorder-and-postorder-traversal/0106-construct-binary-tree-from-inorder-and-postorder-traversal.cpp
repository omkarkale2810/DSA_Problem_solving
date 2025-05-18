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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int instart ,int inend , int postart , int poend){
        if(instart > inend){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[poend]);

        int i = instart;

        while(i <= inend){
            if(root->val == inorder[i]){
                break;
            }
            i++;
        }
        int lsize = i - instart;
        int rsize = inend - i;

        root->left = solve(inorder,postorder,instart,i-1,postart,postart+lsize-1);
        root->right = solve(inorder,postorder,i+1,inend,poend - rsize,poend-1);

        return root;
        

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return solve(inorder,postorder,0,n-1,0,n-1);
    }
};