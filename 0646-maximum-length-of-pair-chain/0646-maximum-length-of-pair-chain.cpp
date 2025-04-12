class Solution {
public:

    int solve(int idx , int p , int n , vector<vector<int>>& pair , vector<vector<int>>& dp ){
        if(idx >= n){
            return 0;
        }
        if(dp[idx][p+1]!=-1){
            return dp[idx][p+1];
        }
        int take = 0;
        if(p == -1 || pair[p][1] < pair[idx][0]){
            take = 1 + solve(idx+1 , idx , n  , pair , dp);
        }
        int nottake = solve(idx+1 , p , n  , pair , dp);
        return dp[idx][p+1] = max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin() , pairs.end());
        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        return solve( 0 , -1 , n , pairs ,  dp);
    }
};