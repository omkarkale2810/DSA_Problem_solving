/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode* , TreeNode*> mp;
    
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left != nullptr){
                TreeNode* leftc = curr->left;
                mp[leftc] = curr;
                q.push(leftc);
            }
            if(curr->right != nullptr){
                TreeNode* rightc = curr->right;
                mp[rightc] = curr;
                q.push(rightc);
            }

        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        bfs(root);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int currDist = 0;
        while(!q.empty()){
            int size = q.size();
            if(currDist == k){
                for(int i = 0; i < size; ++i){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

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

                if(mp.find(curr) != mp.end() && visited.find(mp[curr]) == visited.end()){
                    q.push(mp[curr]);
                    visited.insert(mp[curr]);
                }
            }
            currDist++;
        }

        return ans;
    }
};