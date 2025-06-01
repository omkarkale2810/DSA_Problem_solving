class Solution {
public:
    int M = 1e9+7;
    int countHomogenous(string s) {
        int l = 0;
        int result = 0;
        int n  = s.length();
        for(int i = 0 ; i < n ; i++){
            if(i > 0 && s[i-1] == s[i]){
                l++;
            }
            else{
                l = 1;
            }
            result = (result +  l)%M;
        }
        return result%M;
    }
};