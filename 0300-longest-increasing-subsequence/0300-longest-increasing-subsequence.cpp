class Solution {
public:
    int solve(int idx , int p , vector<int>& nums , int n , vector<vector<int>>& dp){
        if(idx >= n){
            return 0;
        }
        if(dp[idx][p + 1] != -1){
            return dp[idx][p + 1];
        }
        int take = 0;
        if(p == -1 || nums[p] < nums[idx]){
            take = 1 + solve(idx + 1, idx, nums, n, dp);
        }
        int nottake = solve(idx + 1, p, nums, n, dp);
        return dp[idx][p + 1] = max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, n, dp);
    }
};