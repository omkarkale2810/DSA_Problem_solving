class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        int minch1 = max(0,n-2*limit);
        int maxch1 = min(  n , limit);

        for(int i = minch1 ; i <= maxch1 ; i++){
            int remaining_can_for_two_child = n - i;

            int minch2 = max( 0, remaining_can_for_two_child - limit);
            int maxch2 = min( remaining_can_for_two_child,limit);  
            ways += maxch2-minch2+1;
        } 
        return ways;
        
    }
};