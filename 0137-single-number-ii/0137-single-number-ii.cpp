class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
         int result = 0;
        
        for(int i = 0; i<32; i++) {
            
            int temp = (1 << i);
            
            int countOne  = 0;
            int countZero = 0;
            
            for(int &num : nums) {
                
                if((num&temp) == 0) {
                    countZero++;
                } else {
                    countOne++;
                }
                
            }
            
            if(countOne % 3 == 1) {
                result = (result | temp);
            }
            
        }
        
        return result;
        
        // int ones = 0;
        // int twos = 0;
        // int n = nums.size();
        // for(int i = 0 ; i < n ; i++)
        // {
        //     ones = ((nums[i]^ones)&~(twos));
        //     twos = ((nums[i]^twos)&~(ones));
        // }
        // return ones;
    }
};