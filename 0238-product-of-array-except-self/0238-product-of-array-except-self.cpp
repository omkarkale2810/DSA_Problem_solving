class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.begin(), nums.end());
        int n  = nums.size();

        vector<int> prefix(nums.begin(), nums.end());
        vector<int> sufix(nums.begin(), nums.end());
        
        for(int i = 1 ; i < n ; i++){
            prefix[i] *= prefix[i-1];
            sufix[n-1-i] *= sufix[n-i];
        }
        ans[0] = sufix[1];
        ans[n-1] = prefix[n-2];
        for(int i = 1 ; i < n-1 ; i++){
            ans[i] = sufix[i+1]*prefix[i-1];
        }
        return ans;


    }
};