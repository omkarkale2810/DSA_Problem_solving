class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int maxsum = 0;
        for(int i = 0 ; i < n ; i++){

            if(mp.find(nums[i]) == mp.end() && nums[i] >= 0){
                maxsum += nums[i];
            }

            mp[nums[i]]++;
        }
        return maxsum == 0 ? *max_element(nums.begin(), nums.end()) : maxsum;

    }
};