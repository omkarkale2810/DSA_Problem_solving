class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int n = bank.size();
        int m = bank[0].size();
        int prev_beam = 0;
        for(int i = 0 ; i < n ; i++)
        {   
            int beam = 0;
            for(int j = 0 ; j < m ; j++){
                if(bank[i][j] == '1'){
                    beam++;
                }
            }
            if(beam != 0){
                ans += prev_beam * beam;
                prev_beam = beam;
            }
        }
        return ans;
    }
};