class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long c = 0;
        long long maxc = 0;
        long long maxe = -1;
        for(int p = 0 ; p < n ; p++){
            maxe = max((int)maxe,nums[p]);
        }
        for(int p = 0 ; p < n ; p++){
            if(maxe==nums[p])
                maxc++;
        }
        if(maxc < k){
            return 0;
        }
        int i = 0 , j = 0;
        unordered_map<int , int>mp;
        long long localmax = 0;
        while(j < n){
            mp[nums[j]]++;
            while(mp[maxe] >= k){
                c += n-j;
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;

        }
        return c;
    }
};