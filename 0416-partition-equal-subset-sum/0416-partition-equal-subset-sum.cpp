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
        // vector<vector<int>> dp(n , vector<int>(target + 1 , -1));
        // return solve(target , 0 , nums , n , dp);
        
        vector<vector<bool>> dp(n , vector<bool>(target + 1 , false));
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = true;
        }

        if(nums[0] <= target) dp[0][nums[0]] = true;

        for(int i = 1 ; i < n ; i++){
            for(int j = 1; j <= target ; j++){
                bool not_take = dp[i-1][j];
                bool take = false;
                if(j >= nums[i]){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take || not_take;
            }
        }

        return dp[n-1][target];
    }
};