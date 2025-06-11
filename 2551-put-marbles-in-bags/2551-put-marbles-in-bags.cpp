class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        vector<long long> pairsum(n-1 , 0);

        for(int i = 0 ; i < n-1 ; i++){
            pairsum[i] = weights[i] + weights[i+1];
        }

        sort(pairsum.begin(),pairsum.end());
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i = 0 ; i < k-1 ; i++){
            sum1 += pairsum[i];
            sum2 += pairsum[n-2-i];
        }
        return sum2-sum1;
    }   
};