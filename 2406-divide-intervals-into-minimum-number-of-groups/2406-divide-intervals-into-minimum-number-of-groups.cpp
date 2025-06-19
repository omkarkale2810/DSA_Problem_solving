class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();

        int i = 0;
        int j = n-1;

        sort(intervals.begin(),intervals.end());

        while(j >= i){
            
            while(intervals[j][1] > intervals[i][1]){
                j--;
            }
            i++;
        }
        return i;
    }
};