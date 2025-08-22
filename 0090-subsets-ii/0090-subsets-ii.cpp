class Solution {
    set<vector<int>> st;
public:
    void solve(vector<int>& curr, vector<int> &nums, int idx){
        if(idx == nums.size()){
            st.insert(curr);
            return;
        }

        curr.push_back(nums[idx]);
        solve(curr, nums, idx+1);
        curr.pop_back();
        solve(curr, nums, idx+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(curr, nums, 0);
        for(auto& it: st){
            ans.push_back(it);
        }
        return ans;
    }
};