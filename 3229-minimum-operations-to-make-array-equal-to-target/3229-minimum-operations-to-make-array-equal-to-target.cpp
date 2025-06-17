class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        
        // vector<int> diff(n,0);

        // for(int i = 0 ; i < n ; i++){
        //     diff[i] = target[i]-nums[i];
        // }

        long long ans = 0;

        int curr = 0;
        int prev = 0;

        for(int i = 0 ; i < n ; i++){
            int curr = target[i]-nums[i];

            if( (prev < 0 && curr > 0) || (prev > 0 && curr < 0) ){
                ans += abs(curr);
            }
            else if(abs(prev) < abs(curr)){
                ans += abs(curr-prev);
            }
            prev = curr;
        }

        return ans;
    }
};