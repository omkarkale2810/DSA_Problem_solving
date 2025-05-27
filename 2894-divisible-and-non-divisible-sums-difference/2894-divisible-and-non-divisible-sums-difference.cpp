class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = (n*(n+1))/2;
        if(m > n){
            return sum;
        }
        int k = n/m;

        return sum - m * k * (k+1);
    }
};