class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int darr = 0;
        unordered_set<int> st;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
        }
        darr = st.size();
        int i = 0;
        int j = 0;
        int ans = 0;

        unordered_map<int,int> mp;
        while(j < n){
            mp[nums[j]]++;

            while(mp.size() == darr){
                ans += (n-j);
                mp[nums[i]]--;

                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;

        }
        return ans;
    }
};