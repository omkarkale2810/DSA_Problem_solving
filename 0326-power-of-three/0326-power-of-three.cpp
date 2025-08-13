class Solution {
public:
    bool solve(int n){
        if(n == 1){
            return true;
        }
        if(n < 0){
            return false;
        }
        if(n%3 != 0){
            return false;
        }
        return solve(n/3);
    }
    bool isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }

        double x = log10(n)/log10(3); 

        return x == (int)x;
        // return solve(n);

    }
};