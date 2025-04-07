class Solution {
public:
    bool solve(int x , int i , vector<int>& nums , int n , vector<vector<int>>& dp){
        if(x == 0){
            return true;
        }
        if( i >= n || x < 0){
            return false;
        }
        if(dp[i][x] != -1){
            return dp[i][x];
        }

        bool take = solve( x - nums[i] , i+1 , nums , n , dp);
        bool not_take = solve( x  , i+1 , nums , n , dp);

        return dp[i][x] = (take || not_take);
    }
    bool canPartition(vector<int>& nums) {
        int s  = accumulate(nums.begin(), nums.end(), 0);
        if(s % 2 != 0){
            return false;
        }
        int target = s / 2;
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(target + 1 , -1));
        return solve(target , 0 , nums , n , dp);
    }
};