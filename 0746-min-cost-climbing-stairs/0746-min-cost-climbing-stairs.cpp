class Solution {
public:
    int solve(int i , vector<int>& cost,int n){
        if(i > n-1){
            return 0;
        }
        int onestep = cost[i] + solve(i+1 , cost , n);
        int twostep = cost[i] + solve(i+2 , cost , n);
        return min(onestep , twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        return min(solve(0,cost,n),solve(1,cost,n));
    }
};