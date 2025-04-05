class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         int n = nums.size();
        if (n < 3)
            return 0;

        vector<int> max_prefix(n, 0);
        vector<int> max_suffix(n, 0);

        max_prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            max_prefix[i] = max(max_prefix[i - 1], nums[i]);
        }

        max_suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            max_suffix[i] = max(max_suffix[i + 1], nums[i]);
        }

        long long maxi = 0;
        for (int j = 1; j < n - 1; j++) {
            maxi = max(maxi, (long long)(max_prefix[j - 1] - nums[j]) *
                                 max_suffix[j + 1]);
        }

        return maxi;
    }
};