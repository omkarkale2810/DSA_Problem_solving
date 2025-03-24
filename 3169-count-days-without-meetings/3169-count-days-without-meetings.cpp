class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = days;
        vector<bool> day(n+1,true);
        for(auto &vec : meetings){
            int start = vec[0];
            int end = vec[1];
            while(start <= end){
                day[start]=false;
                start++;
            }
        }
        int c = 0;
        for(int i = 1 ; i <= n ; i++){
            if(day[i] == true)
                c++;

        }
        return c;
        
    }
};