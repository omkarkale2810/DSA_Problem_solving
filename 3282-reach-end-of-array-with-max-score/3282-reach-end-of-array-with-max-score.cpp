class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long result = 0;

        int i = 0; 
        int j = 0;
        int n = nums.size();
        if(n == 0){
            return -1;
        }
        while(i < n && j < n){

            if( nums[j] > nums[i] || j == n-1){
                result += (j-i)*nums[i];
                i=j;
            }
            j++;
        }
        return result;

    }
};