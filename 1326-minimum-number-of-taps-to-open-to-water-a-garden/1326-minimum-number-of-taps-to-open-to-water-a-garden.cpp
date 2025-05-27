class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startend(n+1 , 0);

        for(int i = 0 ; i <= n ; i++){
            int start = max( 0 , i-ranges[i]);
            int end = min( n , ranges[i] + i);
            startend[start] = max(startend[start] , end);
        }

        int currtap = 0;
        int maxend  = 0;
        int tap = 0;
        for(int i = 0 ; i <= n ; i++){
            if( i > maxend){
                return -1;
            }
            if(currtap < i){
                tap++;
                currtap = maxend;
            }
            maxend = max(maxend , startend[i]);
        }
        return tap;
    }
};