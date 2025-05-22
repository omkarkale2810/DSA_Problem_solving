class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightmax(n,0);
        int maxi = -1;
        for(int i = n-1; i >= 0 ;i--){
            maxi = max(maxi , nums[i]);
            rightmax[i] = maxi;
        }
        int i = 0 , j = 0;
        int ans = 0;
        while( j < n && i < n ){
            if(nums[i] <= rightmax[j]){
                ans = max(ans , j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;

    }   
};