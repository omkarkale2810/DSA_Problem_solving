class Solution {
public:

    int solve(int i1, int i2 , string& s, string& t){

        if( i2 == t.length() ){
            return s.length() - i1;
        }
        if( i1 == s.length()){
           return t.length()  - i2; 
        }
        if(s[i1] == t[i2]){
            return solve(i1+1, i2+1, s, t);
        }
        
        int ins = 1 + solve(i1, i2+1, s, t);
        int del = 1 + solve(i1+1, i2, s  , t);
        int rep = 1 + solve(i1+1, i2+1, s, t);

        return min({ins, del, rep});
        
    }

    int minDistance(string word1, string word2) {
        return solve(0, 0 , word1, word2 );
    }
};