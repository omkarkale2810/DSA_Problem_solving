class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int M;
    int N;
    void dfs(int i , int j ,queue<pair<int,int>>& q ,vector<vector<int>>& grid , vector<vector<bool>>& visited){
        if(i < 0 || i >= M || j < 0 || j >= N || visited[i][j] == true || grid[i][j] == 0){
            return;
        }
        visited[i][j] = true;
        q.push({i,j});
        dfs(i , j-1 , q , grid , visited);
        dfs(i , j+1 , q , grid , visited);
        dfs(i-1 , j , q , grid , visited);
        dfs(i+1 , j , q , grid , visited);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        M = m;
        N = n;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        bool found = false;
        for(int i = 0 ; i < m && !found; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    dfs(i , j , q, grid , visited);
                    found = true;
                    break;
                }
            }
        }
        int step = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<int,int> curr = q.front();
                int i = curr.first;
                int j = curr.second;
                q.pop();
                if(grid[i][j] == 1 && visited[i][j] == false){
                    return step;
                }
                visited[i][j] = true;
                for(auto& dir : dirs){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    
                    if(new_i < 0 || new_i >= M || new_j < 0 || new_j >= N || visited[new_i][new_j])
                        continue;
                        
                    if(grid[new_i][new_j] == 1){
                        return step;  // Found second island
                    }
                    
                    visited[new_i][new_j] = true;
                    q.push({new_i, new_j});
                }
            } 
            step++;
        }
        return step;


    }
};