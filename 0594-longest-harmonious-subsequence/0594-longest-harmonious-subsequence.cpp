class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;

        for(int& it: nums){
            mp[it]++;
        }

        int ans = 0;
        vector<vector<int>> temp;
        
        for(auto& [ele, freq]: mp){
            temp.push_back({ele,freq});
        }

        if(temp.size() <= 1){
            return 0;
        }

        for(int i = 1; i < temp.size() ; i++){
            if( (temp[i][0] - temp[i-1][0]) == 1){
                ans = max(ans, temp[i-1][1] + temp[i][1]);
            }
        }
        return ans;
    }
};