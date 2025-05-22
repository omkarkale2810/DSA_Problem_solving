class Solution {
public:
    int M = 1e9+7;
    int dp[51][51][101];
    int solve(int idx , int& n , int& m , int& k , int maxtillnow , int searchcost){
        
        if(idx == n){
            if(searchcost == k){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(maxtillnow != -1 && dp[idx][searchcost][maxtillnow]  != -1){
            return dp[idx][searchcost][maxtillnow];
        }
        int result = 0;

        for(int i = 1 ; i <= m ; i++){
            if(maxtillnow < i){
                result = (result + solve(idx+1 , n , m , k , i , searchcost+1))%M;
            }
            else{
                result = (result + solve(idx+1 , n , m , k , maxtillnow ,searchcost))%M;
            }
        }
        if(maxtillnow!= -1){
            dp[idx][searchcost][maxtillnow] =  result%M;
        }
        return result%M;

    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0 , n , m , k , -1 , 0);   
    }
};