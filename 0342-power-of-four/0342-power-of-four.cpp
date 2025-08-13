class Solution {
public:
    // TLE
    // bool solve(int n){
    //     if(n == 1){
    //         return true;
    //     }
    //     if(n < 0){
    //         return false;
    //     }
    //     if(n%4 != 0){
    //         return false;
    //     }
    //     return solve(n/4);
    // }
    bool isPowerOfFour(int n) {
        if(n <= 0){
            return false;
        }

        double x = log10(n)/log10(4); 

        return x == (int)x;
    }
};