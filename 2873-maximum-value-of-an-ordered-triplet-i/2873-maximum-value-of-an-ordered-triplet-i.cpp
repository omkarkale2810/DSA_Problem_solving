class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            long long n1 = nums[i];
            for(int j = i+1 ; j < n ; j++ ){
                long long n2 = nums[j];
                for(int k = j+1 ; k < n ; k ++){
                    long long n3 = nums[k];
                    maxi = max(maxi , ((n1-n2)*n3)); 
                }
            }
        }
        return maxi;
    }
};