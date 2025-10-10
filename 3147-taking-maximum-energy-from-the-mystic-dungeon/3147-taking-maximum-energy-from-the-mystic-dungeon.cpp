class Solution {
public:
    int solve(int idx, bool started, vector<int>& energy, int& n, int& k){
        if(idx >= n){
            return started ? 0 : INT_MIN;
        }

        int take = energy[idx] + solve(idx+k, true, energy, n, k);
        
        int skip = INT_MIN;
        if(started == false){
            skip = solve(idx+1, false, energy, n, k);
        }

        return max(take, skip);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        return solve(0, false, energy, n , k);
    }
};