class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        long long result = 0;
        for(auto& it : mp){
            int count = it.second;
            if (count > 1) {
                result += (count * (count - 1)) / 2;
            }
        }
        return result;
    }
};