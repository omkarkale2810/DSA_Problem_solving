class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int zc = 0;

        int maxlen = 0;
        int len = 0;

        while( j < n ){
            
            if(nums[j] == 0){
                zc++;
            }
            len++;

            while(zc > 1){
                if(nums[i] == 0){
                    zc--;
                }
                i++;
                len--;
            }   
            if(zc <= 1){
                maxlen = max(len,maxlen);
            }
            j++;
        }
        return maxlen-1;
    }
};