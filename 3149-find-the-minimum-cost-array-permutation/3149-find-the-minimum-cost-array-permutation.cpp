class Solution {
public:
    int minscore = INT_MAX;
    vector<int> result;
    int n = 0;

    void solve(vector<int>& nums, vector<bool>& visited, vector<int>& temp, int score) {
        if (minscore <= score)  
            return;

        if (temp.size() == n) {
            score += abs(temp.back() - nums[temp[0]]);
            if (score < minscore) {
                minscore = score;
                result = temp;   
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.push_back(i);
                solve(nums, visited, temp, score + abs(temp[temp.size() - 2] - nums[temp[temp.size() - 1]]));
                temp.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        vector<bool> visited(n, false);
        vector<int> temp = {0}; 
        visited[0] = true;

        solve(nums, visited, temp, 0);
        return result;
    }
};