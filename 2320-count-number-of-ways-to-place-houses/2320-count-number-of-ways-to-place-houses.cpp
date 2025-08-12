class Solution {
public:
    const int MOD = 1e9 + 7;
    int N = 0;
    int solve(int i, vector<long long>& dp){
        if(i == N){
            return dp[i] = 2;
        }
        if(i > N){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int take = solve(i+2, dp)  % MOD;
        int skip = solve(i+1, dp)  % MOD;
        return dp[i] = (take+skip) % MOD;

    }
    int countHousePlacements(int n) {
        N = n;
        vector<long long> dp(n+1, -1);
        int ans = solve(1, dp) % MOD;
        return (ans*ans)% MOD;
    }
};