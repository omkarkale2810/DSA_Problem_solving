class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int prev = INT_MIN;
        int c = 0;
        for(int i = 0 ; i < nums.size() ; i++){            
            int minval = nums[i] - k;
            int maxval = nums[i] + k;

            if(prev < minval){
                prev = minval;
                c++;
            }
            else if(prev < maxval){
                prev++;
                c++;
            }
        }
        return c;
        
    }
};