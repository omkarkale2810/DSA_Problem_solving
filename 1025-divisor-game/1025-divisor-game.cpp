class Solution {
public:
    bool solve(int n , bool flag ){
        if( n == 1 && flag){
            return true; 
        }
        for(int i = 1 ; i < n ; i++){
            if(n%i == 0){
                return solve( n-i , !flag);
            }
        }
        return false;
    }
    bool divisorGame(int n) {
    //    return n%2 == 0;
        bool flag = 1;
        vector<bool> dp(n+1,0);
        return !solve( n , 1 );
        


    }
};