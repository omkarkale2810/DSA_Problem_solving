class Solution {
public:
    // GOT MLE AT 941 TEST CASE
    // int solve(int idx, int prev, int val, vector<int>& nums, vector<vector<vector<int>>> &dp) {
    //     if (idx == nums.size()) return 0;

    //     if (dp[idx][prev + 1][val + 1] != -1) return dp[idx][prev + 1][val + 1];

    //     int take = 0;
    //     if (prev == -1) {
    //         take = 1 + solve(idx + 1, idx, -1, nums, dp);
    //     } else {
    //         int new_val = (nums[prev] + nums[idx]) % 2;
    //         if (val == -1 || val == new_val) {
    //             take = 1 + solve(idx + 1, idx, new_val, nums, dp);
    //         }
    //     }

    //     int skip = solve(idx + 1, prev, val, nums, dp);
    //     return dp[idx][prev + 1][val + 1] = max(take, skip);
    // }

    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(3, -1)));
        // return solve(0, -1, -1, nums, dp);

        // even - even

        int ans = INT_MIN;
        int curr = 0;

        for(int i = 1 ; i < n; i++){
            if(nums[i-1]%2 == 0 && nums[i]%2 == 0){
                curr += 2;
            }
        }

        ans = max(ans, curr);

        // odd- odd
        curr = 0;
        for(int i = 1 ; i < n; i++){
            if(nums[i-1]%2 != 0 && nums[i]%2 != 0){
                curr += 2;
            }
        }

        ans = max(ans, curr);

        // odd-even  
        curr = 0;
        for(int i = 1 ; i < n; i++){
            if(nums[i-1]%2 != 0 && nums[i]%2 == 0){
                curr += 2;
            }
        }

        ans = max(ans, curr);

        // even  odd-
        curr = 0;
        for(int i = 1 ; i < n; i++){
            if(nums[i-1]%2 == 0 && nums[i]%2 != 0){
                curr += 2;
            }
        }

        ans = max(ans, curr);

        return ans;
    }
};