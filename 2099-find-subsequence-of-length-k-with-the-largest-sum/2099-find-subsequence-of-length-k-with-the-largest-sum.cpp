class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        sort(begin(nums) ,end(nums));
        vector<int> ans;
        int n = nums.size();
        for(int i = n-k ; i < n ; i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};