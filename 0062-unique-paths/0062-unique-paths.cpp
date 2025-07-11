class Solution {
public:
    
    int solve(int i, int j, int& m, int& n, vector<vector<bool>>& visited, vector<vector<int>>& dp){
        if(i >= m || j >= n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        int down = solve(i+1, j , m , n , visited, dp);
        int righ = solve(i, j+1 , m , n , visited, dp);

        return dp[i][j] = down + righ;
    }


    int uniquePaths(int m, int n) {
        vector<vector<bool>> visited(m, vector<bool>(n , false)); 
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));
        
        return solve(0, 0, m, n,  visited, dp);
    }
};