class Solution {
public:
    int n = 0;

    int solve(vector<vector<int>>& events, int idx, int k, vector<vector<int>>& dp){
        if(idx >= n || k == 0){
            return 0;
        }

        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        int end = events[idx][1];
        int val = events[idx][2];

        int skip = solve(events, idx+1, k, dp);
        int j = idx+1;
        
        for(; j < n ; j++){
            if(events[j][0] > end){
                break;
            }
        } 
        int take = val + solve(events, j, k-1, dp);

        return dp[idx][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(begin(events), end(events));
        vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        return solve(events, 0, k, dp);
    }
};