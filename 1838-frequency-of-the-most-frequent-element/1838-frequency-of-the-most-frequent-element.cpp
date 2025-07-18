class Solution {
public:
    int binary_search(int right, int k, vector<int>& nums, vector<long>& presum){
        
        int target = nums[right];
        int left = 0;

        int target_idx = right;
        int best_idx = target_idx;

        while( left <= right){
            int mid = ( right + left ) / 2;

            long actsum = presum[target_idx] - presum[mid] + nums[mid];
            long sum = (target_idx - mid + 1) * target;

            int opp = sum - actsum;

            if(opp <= k){
                right = mid-1;
                best_idx = mid;
            }
            else{
                left = mid+1;
            }

        }
        return target_idx - best_idx+1;

    }
    
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        vector<long> presum(n , 0);
        presum[0] = nums[0];

        for(int i = 1 ; i < n ; i++){
            presum[i] = nums[i]+presum[i-1];
        }

        int maxlen = 0;

        for(int i = 0 ; i < n ; i++){
            long len = binary_search(i, k, nums, presum);
            maxlen = max(maxlen,(int)len);
        }
        return (int)maxlen;
    }
};