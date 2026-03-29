class Solution {
public:
    int solve(int idx, int prev, int n, vector<int>& nums,vector<vector<int>>& dp){
        if(idx >= n){
            return 0;
        }
        if(prev != -1 && dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        int take = 0;
        if(prev == -1 || nums[prev] < nums[idx]){
            take = 1 + solve(idx+1, idx, n , nums,dp); 
        }
        int skip = solve(idx+1, prev, n , nums,dp);
        return prev == -1? max(take, skip):dp[idx][prev] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, -1, n, nums, dp);
    }
};