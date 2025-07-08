class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> sToT, tToS;

        int n = s.length();

        for(int i = 0 ;  i < n ; i++){
            if(sToT.find(s[i]) == sToT.end()){
                sToT[s[i]] = t[i];
            }
            if(tToS.find(t[i]) == tToS.end()){
                tToS[t[i]] = s[i];
            }
            if(sToT[s[i]] != t[i]){
                return false;
            }
            if(tToS[t[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
};