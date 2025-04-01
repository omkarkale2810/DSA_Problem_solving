class Solution {
public:
    long long solve(int i , int n , vector<vector<int>>& que , vector<long long>& dp){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int take = que[i][0] + solve( i + que[i][1] + 1 , n , que,dp);
        int nottake = 0 + solve( i + 1 , n , que,dp);

        return dp[i] = max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& que) {
        // int n = que.size();
        // vector<long long> dp(n+1 , 0);
        // return solve(0,n,questions,dp);

        int n = que.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int next = i + que[i][1] + 1;
            long long take = que[i][0] + (next < n ? dp[next] : 0);
            long long nottake = dp[i + 1];

            dp[i] = max(take, nottake);
        }
        return dp[0];
    }
};