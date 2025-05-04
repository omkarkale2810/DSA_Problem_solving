class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        vector<int> hash(100,0);
        int c = 0;
        for(int i = 0 ; i < n ; i++){
            int f = dominoes[i][0];
            int s = dominoes[i][1];
            if(f>s){
                swap(f,s);
            }
            int num = f*10 + s;
            c += hash[num];
            hash[num]++;
        }
        
        return c;

    }
};