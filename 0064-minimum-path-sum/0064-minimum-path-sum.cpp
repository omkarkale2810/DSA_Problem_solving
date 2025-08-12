class Solution {
public:
    // int m  = 0;
    // int n  = 0;
    // This is backtracking approach gave me TLE
    // void solve(int i, int j, int curr, vector<vector<int>>& grid, vector<vector<bool>>& visited){
    //     if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true){
    //         return;
    //     }
        
    //     curr += grid[i][j];

    //     if( i == m-1 && j == n-1 ){
    //         minpath = min(curr, minpath);
    //         return;
    //     }
        
    //     visited[i][j] = true;
    //     solve(i+1, j, curr, grid, visited);
    //     solve(i, j+1, curr, grid, visited);
    //     visited[i][j] = false;
    // }

    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return dp[i][j] = grid[i][j];
        }
        if(i < 0 || j < 0){
            return 1e9;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up   = grid[i][j] + solve(i-1, j, grid, dp); 
        int left = grid[i][j] + solve(i, j-1, grid, dp);
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m-1, n-1, grid, dp);
    }
};