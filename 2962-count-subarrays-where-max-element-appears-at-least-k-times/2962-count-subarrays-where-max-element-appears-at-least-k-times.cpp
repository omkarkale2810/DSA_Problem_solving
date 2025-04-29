class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long c = 0;
        long long maxe =  *max_element(nums.begin(), nums.end());;
    
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