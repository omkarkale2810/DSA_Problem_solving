class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long sum = 0;
        long long c = 0;
        while(j < n){
            sum += nums[j];
            while(sum*(j-i+1) >= k){
                sum -= nums[i];
                i++;
            }
            c += (j-i+1);
            j++;
        }
        return c;


    }
};