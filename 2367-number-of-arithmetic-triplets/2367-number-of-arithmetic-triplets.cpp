class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int c = 0;
        for(int i = 0 ; i < n-2 ; i++){
            for(int j = i+1 ; j < n-1 ; j++){
                for(int k = 0 ; k < n ; k++){
                    if(nums[k]-nums[j] == diff && nums[j]-nums[i] == diff){
                        c++;
                    }
                }   
                
            }
        }
        return c;
    }
};