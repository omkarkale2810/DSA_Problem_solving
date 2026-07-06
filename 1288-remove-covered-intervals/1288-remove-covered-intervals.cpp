class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int c = 0;
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<bool> hash(n, false);
        for(int i = 0 ; i < n ; i++){
            if(hash[i] == false){
                for(int j = i+1; j < n ; j++){
                    if((intervals[i][1] >= intervals[j][1]) && (hash[i] == false && hash[j] == false)){
                        hash[j] = true;    
                        c++;
                    }
                    else{
                        break;
                    }
                }    
            }
        }
        return n-c;
    }
};