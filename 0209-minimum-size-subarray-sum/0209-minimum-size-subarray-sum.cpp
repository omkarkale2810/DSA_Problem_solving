class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = -1;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            mp[sum] = i;
        }

        int minilen = INT_MAX;
        sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];

            int remsum = sum - target;
            if(mp.find(remsum) != mp.end()){
                int idx = mp[remsum];

                minilen = min(minilen , i-idx);
            } 
        }

        return minilen == INT_MAX ? 0 : minilen;
    }
};