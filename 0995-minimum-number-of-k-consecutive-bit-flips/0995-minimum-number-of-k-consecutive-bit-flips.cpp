class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;

        int currflip = 0;
        vector<bool> flipped(n+1,false);

        for(int i = 0 ; i < n ; i++){
            
            if(i >= k && flipped[i-k] == true){
                currflip--;
            }

            if(nums[i] == 1 && currflip % 2 != 0 || nums[i] == 0 && currflip % 2 == 0){
                if(i + k > n){
                    return -1; 
                }
                currflip++;
                flipped[i] = true;
                flips++;
            }
        }
        return flips;
    }
};