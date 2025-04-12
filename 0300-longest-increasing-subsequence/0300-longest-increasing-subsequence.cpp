class Solution {
public:
    int solve(int idx , int p , vector<int>& nums , int n){
        if( idx >= n ){
            return 0;
        }
        int take = 0;
        if( p == -1 || nums[p] < nums[idx]){
            take = 1 + solve(idx+1 , idx , nums , n);
        }
        int nottake = solve(idx+1 , p , nums , n);
        return max(take,nottake);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(0,-1,nums,n);
    }
};