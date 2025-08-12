class Solution {
public:
    long long solve(int i, int j, vector<vector<int>> &grid, int& n, vector<vector<long long>>& dp){
        if(j < 0 || j >= n){
            return 1e9;
        }
        if( i == n-1 ){
            return dp[i][j] = grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        long long ld = grid[i][j] + solve(i+1,j-1, grid, n, dp);
        long long sd = grid[i][j] + solve(i+1,j  , grid, n, dp);
        long long rd = grid[i][j] + solve(i+1,j+1 ,grid, n, dp);
        return dp[i][j] = min({ld,sd,rd}); 
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int ans = INT_MAX;

        // vector<vector<long long>> dp(n, vector<long long>(n, -1));
        
        // for(int i = 0; i < n ; i++){
        //     ans = min(ans, (int)solve(0, i, matrix, n, dp));
        // }
        // return ans;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0 ; i < n ; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = 0 ; j < n ; j++){
                int ld = (j > 0)     ? dp[i + 1][j - 1] : 1e9;;
                int rd = dp[i + 1][j];;
                int sd = (j < n - 1) ? dp[i + 1][j + 1] : 1e9;;
                dp[i][j] = matrix[i][j] + min({ld, sd, rd});

            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};