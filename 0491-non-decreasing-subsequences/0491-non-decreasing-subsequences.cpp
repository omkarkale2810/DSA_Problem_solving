class Solution {
public:
    set<vector<int>> unique_ans;  
    vector<vector<int>> ans;
    
    void solve(int idx, vector<int> curr,vector<int>& nums){
        if(idx >= nums.size()){
            if(curr.size() >= 2){
                unique_ans.insert(curr);
            }
            return;
        }
        if(!curr.empty()){
            int ele = curr.back();
            if(ele <= nums[idx]){
                curr.push_back(nums[idx]);
                solve(idx+1 ,curr ,nums);
                curr.pop_back();
            }
        }
        else{
            curr.push_back(nums[idx]);
            solve(idx+1, curr , nums);
            curr.pop_back();
        }
        solve(idx+1 , curr, nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        solve(0 , curr , nums);
        for (const auto& seq : unique_ans) {
            ans.push_back(seq);
        }
        return ans;
    }
};