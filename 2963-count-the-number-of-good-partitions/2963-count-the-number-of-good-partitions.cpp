class Solution {
public:
    int M = 1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int j = 0;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]] = i;
        }
        j = max(j,mp[nums[i]]);
        int result = 1;
        while( i < n ){
            if(i>j){
                result = (result*2)%M;
            }
            j = max(j,mp[nums[i]]);
            i++;
        }
        return result;
    }
};