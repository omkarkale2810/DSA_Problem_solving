class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int minele = *min_element(nums.begin(), nums.end());
        int maxele = *max_element(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != minele && nums[i] != maxele){
                return nums[i];
            }
        }
        return -1;
    }
};