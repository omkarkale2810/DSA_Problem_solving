class Solution {
public:
    int M = 1e9+7;
    int solve(int n , vector<int>& dp){
        if(dp[n] != -1){
            return dp[n];
        }
        if(n == 1 || n == 2){
            return n;
        }
        if( n == 3){
            return 5;
        }
        return dp[n] = (2*solve(n-1 , dp)%M + solve(n-3 , dp)%M)%M;
    }
    int numTilings(int n) {
        vector<int> dp(n+1,-1);
        // return solve(n  , dp);
        if(n == 1 || n == 2){
            return n;
        }
        if( n == 3){
            return 5;
        }
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4 ; i<=n ; i++){
            dp[i] = ((2*dp[i-1])%M + (dp[i-3]%M))%M;
        }
        return dp[n];
    }
};