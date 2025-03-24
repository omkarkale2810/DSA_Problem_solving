class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = days;
        int start = 0;
        int end = 0;
        
        int c = 0;
       
        sort(meetings.begin() , meetings.end());
        for(auto &vec : meetings){

            if(vec[0] > end){
                c += vec[0] - end - 1;
            }

            end = max(vec[1] , end);
        }
        if(n > end){
            c += n - end ;
        }
        return c;
        
    }
};