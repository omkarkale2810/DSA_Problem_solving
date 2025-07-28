class Solution {
public:
    int solve(vector<int>& nums, int idx, int currOr, int& n , int& maxor){
        if(idx >= n){
            return currOr == maxor ? 1 : 0;
        }
        int take = solve(nums, idx + 1, currOr | nums[idx], n, maxor);
        int nottake = solve(nums, idx + 1, currOr, n, maxor);
        return take + nottake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxor = nums[0];

        for(int i = 1; i < n ; i++){
            maxor |= nums[i];
        }
        return solve(nums,0,0,n,maxor);
    }
};