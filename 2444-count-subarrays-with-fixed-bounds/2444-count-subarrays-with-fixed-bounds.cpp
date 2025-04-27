class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minPos = -1, maxPos = -1, leftBound = -1;
        long long count = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                leftBound = i;
                minPos = -1;
                maxPos = -1;
            }
            if (nums[i] == minK) minPos = i;
            if (nums[i] == maxK) maxPos = i;
            
            if (minPos != -1 && maxPos != -1) {
                count += max(0, min(minPos, maxPos) - leftBound);
            }
        }

        return count;

    }
};