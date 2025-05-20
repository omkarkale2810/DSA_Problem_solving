class Solution {
public:
    int M = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 ; 
        int r = n-1;
        sort(nums.begin() , nums.end());

        vector<int> power(n+1);
        power[0] = 1;
        for(int i = 1 ; i <= n ; i++){
            power[i] = (power[i-1]*2)%M;
        }

        int ans = 0;
        while(r >= l){
            int minele = nums[l];
            int maxele = nums[r]; 
            if(minele + maxele <= target){
                int power_of_2 = r-l;
                ans = (ans% M + power[power_of_2])%M;
                l++;
            }
            else{
                r--;
            }
        } 
        return ans;
    }
};