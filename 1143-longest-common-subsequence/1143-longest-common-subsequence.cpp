class Solution {
public:
    int solve(string a , string b , int i , int j ,  vector<vector<int>> &dp){
        if(i == a.length()){
            return 0;
        }
        if(j == b.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1+solve(a,b,i+1,j+1,dp);
        }
        else{
            ans = max(solve(a,b,i+1,j,dp) , solve(a,b,i,j+1,dp));
        }
        return  dp[i][j] = ans;
    }
    int tabular(string a , string b , int m , int n){
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));

        for(int i =  m-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1+dp[i+1][j+1];
                }
                else{
                    ans = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];

    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        // vector<vector<int>> dp(m , vector<int>(n , -1));
        // return solve(text1,text2,0,0,dp);
        return tabular(text1,text2 , m , n);
    }
};