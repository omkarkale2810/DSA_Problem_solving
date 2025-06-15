class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> temp;

        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }

        while (!mp.empty()) {
            vector<int> temp;
            vector<int> toErase;

            for (auto& [num, freq] : mp) {
                temp.push_back(num);
                mp[num]--;
                if (mp[num] == 0) {
                    toErase.push_back(num);  
                }
            }
            for (int num : toErase) {
                mp.erase(num);
            }

            ans.push_back(temp);  
        }
        
        return ans;
    }
};