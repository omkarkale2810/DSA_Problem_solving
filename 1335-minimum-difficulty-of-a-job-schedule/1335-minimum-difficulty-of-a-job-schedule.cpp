class Solution {
public:
    int solve(vector<int>& jd , int d , int idx , int n, vector<vector<int>>& dp){
        if(dp[d][idx] != -1){
            return dp[d][idx];
        }
        if(d == 1){
            int maxD = jd[idx];
            for(int i = idx ; i < n ; i++){
                maxD = max(maxD , jd[i]);
            }
            return maxD;
        }

        int maxD = jd[idx];
        int result = INT_MAX;

        for(int i = idx ; i <= n-d ; i++){
            maxD = max(maxD , jd[i]);
            int res = maxD + solve(jd, d-1, i+1 , n , dp);
            result = min(result , res);
        }
        return dp[d][idx] = result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n){
            return -1;
        }
        vector<vector<int>> dp(d+1,vector<int>(n+1,-1));
        return solve(jobDifficulty , d , 0 , n , dp);
    }
};