class Solution {
public:
    bool solve(int i, int n, vector<int>& nums, vector<int>& dp){
        if( i >= n ){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        bool result = false;
        if(i+1<n && nums[i] == nums[i+1]){
            result |= solve(i+2,n,nums,dp);
        }
        if( i+2 < n && nums[i] == nums[i+1] && nums[i+1]==nums[i+2]){
            result |= solve(i+3,n,nums,dp);
        }
        if( i+2 < n && nums[i+1]-nums[i] == 1 && nums[i+2]-nums[i+1] == 1){
            result |= solve(i+3,n,nums,dp);
        }
        return dp[i] = result;
        
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};