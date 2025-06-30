class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        int ans = 0;
        for (auto& [num, freq] : mp) {
            if (mp.count(num + 1)) {
                ans = max(ans, freq + mp[num + 1]);
            }
            else if (mp.count(num - 1)) {
                ans = max(ans, freq + mp[num - 1]);
            }
        }

        return ans;
    }
};