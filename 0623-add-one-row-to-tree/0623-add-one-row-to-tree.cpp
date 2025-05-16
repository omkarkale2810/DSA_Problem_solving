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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if( depth == 1 ){
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        int d = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            d++;
            int n = q.size();
            bool flag = false;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                TreeNode* lefttemp = curr->left;
                TreeNode* righttemp = curr->right;
                if(d == depth-1){
                    TreeNode* newl = new TreeNode(val);
                    TreeNode* newr = new TreeNode(val);
                    curr->left = newl;
                    curr->right = newr;
                    newl->left = lefttemp;
                    newr->right = righttemp;
                    flag = true;
                }
                if(lefttemp){
                    q.push(lefttemp);
                }
                
                if(righttemp){
                    q.push(righttemp);
                }
            }
            if(flag){
                break;
            }
        }
        return root;
    }
};