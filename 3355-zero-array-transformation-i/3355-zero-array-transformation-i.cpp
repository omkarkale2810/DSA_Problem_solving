class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int qs = queries.size();
        int n = nums.size();

        vector<int> diffarr(n , 0);
        
        for(int i = 0 ; i < qs ; i++){
            int sidx = queries[i][0];
            int eidx = queries[i][1];
            diffarr[sidx] += 1;
            if(eidx+1 < n)
                diffarr[eidx+1] -= 1;
        }
        vector<int> cumsum;
        int cum = 0;
        for(int i = 0 ; i < diffarr.size() ; i++){
            cum += diffarr[i];
            cumsum.push_back(cum);
        }
        for(int i = 0 ; i < diffarr.size() ; i++){
            if(nums[i] > cumsum[i]){
                return false;
            }
        }
        return true;
    }
};