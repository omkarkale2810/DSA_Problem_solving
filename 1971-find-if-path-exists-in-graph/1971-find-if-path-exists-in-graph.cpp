class Solution {
public:
    int bfs(unordered_map<int , vector<int>>& adj, vector<bool>& visited , int start , int end){
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int s = q.size();
            while(s--){            
                int curr = q.front();
                q.pop();
                if( curr ==  end ){
                    return true;
                }
                for(auto& ngbr: adj[curr]){
                    if(ngbr == end){
                        return true;
                    }
                    if( visited[ngbr] == false){
                        q.push(ngbr);
                        visited[ngbr] = true; 
                    }
                }

            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        return bfs(adj , visited , source , destination);
    }
};