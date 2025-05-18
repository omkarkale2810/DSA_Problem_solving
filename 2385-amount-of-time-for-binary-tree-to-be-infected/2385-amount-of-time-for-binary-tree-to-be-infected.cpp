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
    TreeNode* startnode = nullptr;
    unordered_map<TreeNode*,TreeNode*> cpmap;
    void child_parent_mapping(TreeNode* root , int start){
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            if(curr->val == start){
                startnode = curr;
            }
            q.pop();

            if(curr->left != nullptr){
                TreeNode* leftc = curr->left;
                cpmap[leftc] = curr;
                q.push(leftc);
            }
            if(curr->right != nullptr){
                TreeNode* rightc = curr->right;
                cpmap[rightc] = curr;
                q.push(rightc);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        child_parent_mapping(root,start);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(startnode);
        visited.insert(startnode);

        int currtime = -1;

        while(!q.empty()){

            int size = q.size();
              
            ++currtime;
            for(int i = 0; i < size; ++i){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && visited.find(curr->left) == visited.end()){
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if(curr->right && visited.find(curr->right) == visited.end()){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }

                if(cpmap.find(curr) != cpmap.end() && visited.find(cpmap[curr]) == visited.end()){
                    q.push(cpmap[curr]);
                    visited.insert(cpmap[curr]);
                }
            }
          
        }
        return currtime;
    }
};