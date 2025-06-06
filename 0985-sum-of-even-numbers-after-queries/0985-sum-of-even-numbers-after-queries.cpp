class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i]%2 == 0){
                sum += nums[i]; 
            }
        }
        n = queries.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++ ){
            int val = queries[i][0];
            int idx = queries[i][1];

            if(nums[idx]%2 == 0 && val%2== 0){
                sum += val;
                nums[idx] += val;
            }
            else if(nums[idx]%2 != 0 && val%2 != 0){
                sum += nums[idx]+val;
                nums[idx] = nums[idx]+val;
            }
            else if(nums[idx] != 0 && val%2 != 0){
                sum -= nums[idx];
                nums[idx] += val;
            }
            else{
                nums[idx] = nums[idx] + val;
                
            }
            ans.push_back(sum);
        }
        return ans;
    }
};