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
        int count =0;
        
        while(j < n){
            if(nums[j] == maxe)
                count++;
            while(count >= k){
                c += n-j;
                if(nums[i] == maxe)
                    count--;
                i++;
            }
            j++;
        }
        return c;
    }
};