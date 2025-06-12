class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxdiff = INT_MIN;
        int n = nums.size();
        maxdiff = abs(nums[0]-nums[n-1]);
        for(int i = 1 ; i < n ; i++){
            maxdiff = max(maxdiff , abs(nums[i]-nums[i-1]));
        }
        return maxdiff;
    }
};