class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0 ; i <= n-4 ; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i+1; j <= n-3 ; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j+1;
                int r = n-1;
                while(r > l){
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    
                    if(sum == target){
                        ans.push_back({nums[i] , nums[j] , nums[l] , nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;

                    }
                    else if(sum < target){
                        l++;
                    }
                    else{
                        r--;
                    }

                }

            }
        }
        return ans;

    }
};