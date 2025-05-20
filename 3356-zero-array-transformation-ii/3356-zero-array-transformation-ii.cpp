class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries , int& kk) {
        int n = nums.size();

        vector<int> diffarr(n , 0);
        
        for(int i = 0 ; i <= kk ; i++){
            int sidx = queries[i][0];
            int eidx = queries[i][1];
            int x = queries[i][2];
            diffarr[sidx] += x;
            if(eidx+1 < n)
                diffarr[eidx+1] -= x;
        }
        
        vector<int> cumsum;
        int cum = 0;
        for(int i = 0 ; i < diffarr.size() ; i++){
            cum += diffarr[i];
            cumsum.push_back(cum);
            if(nums[i] > cumsum[i]){
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        
        auto lambda = [](int x) {
            return x == 0;
        };

        if(all_of(begin(nums), end(nums), lambda)) {
            return 0; 
        }
        for(int i = 0 ; i < n ; i++){
            if(isZeroArray(nums,queries , i) == true){
                return i+1;
            }
        }
        return -1;
    }
};