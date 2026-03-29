class Solution {
public:
    int solve(int idx, int n, vector<int> &dp){
        if(idx >= n){
            if(idx == n){
                return 1;
            }
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int one = solve(idx+1, n, dp);
        int two = solve(idx+2, n, dp);
        return dp[idx] = one+two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return solve(0 , n, dp);
    }
};