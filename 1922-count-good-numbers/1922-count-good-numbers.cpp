class Solution {
public:
    const int M = 1e9+7;
    long long power( long long a , long long n ){
        if(n == 0){
            return 1;
        }
        long long half = power(a,n/2);
        long long result = (half*half)%M;
        if(n%2 == 1){
            result = (a * result) % M;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        return (long long)(power( 5,(n+1)/2) * power( 4, n/2 ) )%M;
    }
};