class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diffarr(n,0);
        for(int i = 0 ; i < shifts.size() ; i++){
            int sidx = shifts[i][0];
            int eidx = shifts[i][1];
            int dir = shifts[i][2];
            int x = 1;

            if( dir == 0){
                x = -1;
            }
            else {
                x = 1;
            }
            diffarr[sidx] += x;
            if(eidx+1 < n){
                diffarr[eidx+1] -= x;
            }
        }
        int cumsum = 0;
        vector<int> cumsumarr(n,0);
        for(int i = 0 ; i < n ; i++){
            cumsum += diffarr[i];
            cumsumarr[i] = cumsum;
        }

        for(int i = 0 ; i < n ; i++){
            int shift = cumsumarr[i]%26;

            if(shift < 0){
                shift += 26;
            }

            s[i] = (((s[i] - 'a') + shift)%26 + 'a');

        }
        return s;


    }
};