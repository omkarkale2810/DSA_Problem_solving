class Solution {
public:
    int n = 0;
    int solve(int idx, int amount, int curr, vector<int>& coins,vector<vector<int>>& dp){
        if(idx >= n){
            if(curr == amount){
                return 1;
            }
            return 0;
        }
        if(dp[idx][curr] != -1){
            return dp[idx][curr];
        }
        int take = 0;
        if(curr + coins[idx] <= amount){
            take = solve(idx, amount, curr + coins[idx], coins, dp); 
        }
        int skip = solve(idx+1, amount, curr , coins, dp); 
        return dp[idx][curr] = take+skip;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        int curr = 0;
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n+1, vector<int>(amount+coins[n-1], -1));
        return solve(0, amount, curr, coins, dp);

    }
};