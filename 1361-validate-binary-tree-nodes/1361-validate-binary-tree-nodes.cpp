class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        unordered_map<int,int> child_parent;
        unordered_map<int,vector<int>> adj;
    

        for(int i = 0 ; i < n ; i++){
            
            if(leftChild[i] != -1){
                
                if(child_parent.find(leftChild[i])!=child_parent.end()){
                    return false;
                }
                adj[i].push_back(leftChild[i]);
                child_parent[leftChild[i]] = i;
            }

            if(rightChild[i] != -1){
                if(child_parent.find(rightChild[i])!=child_parent.end()){
                    return false;
                }
                adj[i].push_back(rightChild[i]);
                child_parent[rightChild[i]] = i;
            }
        }
        int root = -1;
        for(int i = 0 ; i < n ; i++){
            
            if( child_parent.find(i) == child_parent.end()){
                if( root != -1) return 0;
                root = i;
            }
        }
        if(root == -1) return false;
        
        int c = 0;
        queue<int> q;
        vector<bool> vis(n,0);

        q.push(root);
        vis[root] = true;
        c = 1;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int it : adj[curr]){
                if(vis[it]==true){
                    return false;
                }
                vis[it] = true;
                q.push(it);
                c++;
            }
        }
        return n == c;

        
    }
};