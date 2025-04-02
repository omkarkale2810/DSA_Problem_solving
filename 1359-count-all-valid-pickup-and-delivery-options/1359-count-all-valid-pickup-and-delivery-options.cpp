class Solution {
public:
    int M = 1e9+7;
    int countOrders(int n) {
        if( n == 1 ){
            return 1;
        }
        long long result = 1;

        for( int i = 2 ; i <= n ; i++){
            int space = 2*(i-1)+1;
            int currpossi = (space*(space+1))/2;
            result *= currpossi;
            result %= M; 
        }
        return result;
    }
};