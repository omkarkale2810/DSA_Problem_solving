class Solution {
public:
    int solve(int idx, int n, int curr,int target, vector<int>& nums){
        if(idx > n-1){
            if(target == curr){
                return 1;
            }
            else{
                return 0;
            }
        }
        int pos = solve(idx+1, n, curr+nums[idx], target, nums);
        int neg = solve(idx+1, n, curr-nums[idx], target, nums);

        return pos+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(0, n ,0 ,target, nums);
    }
};