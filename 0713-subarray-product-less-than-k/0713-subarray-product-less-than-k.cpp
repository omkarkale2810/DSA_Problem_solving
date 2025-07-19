class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 0){
            return 0;
        }

        int count = 0;

        long long mul = 1;
        int i = 0;
        int j = 0;

        while( j < n ){
            mul *= nums[j];

            if((int)mul < k){
                count += j-i+1;
            }
            while( i < j && mul >= k){
                mul /= nums[i];
                i--;
            } 
            j++;
        }
        return count;
    }
};