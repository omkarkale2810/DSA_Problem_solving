class Solution {
public:
    bool solve( int idx , int  n , vector<int>& nums , vector<int>& dp){
        if(idx == n-1 ){
            return dp[idx] = true;
        } 
        if(idx >= n){
            return false;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        for(int i = 1 ; i <= nums[idx] ; i++){
            if (solve(idx + i, n, nums, dp)) {
                return dp[idx] = true;
            }
        }
        return dp[idx]  = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return solve(0,nums.size() , nums , dp);
    }
};