class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<vector<int>>> visited(m,vector<vector<int>>(n, vector<int>(k+1,-1)));

        q.push({0,0,k});
        visited[0][0][k] = 1;
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                vector<int> curr = q.front();
                q.pop();
                int i = curr[0];
                int j = curr[1];
                int k_ = curr[2];

                if(i == m-1 && j == n-1){
                    return step;
                }
                for (auto& dir : dirs) {
                    int ni = i + dir[0], nj = j + dir[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        int new_k = k_ - grid[ni][nj]; // eliminate if obstacle
                        if (new_k >= 0 && visited[ni][nj][new_k] == -1) {
                            visited[ni][nj][new_k] = 1;
                            q.push({ni, nj, new_k});
                        }
                    }
                }
            } 
            step++;
        }
        return -1;

    }
};