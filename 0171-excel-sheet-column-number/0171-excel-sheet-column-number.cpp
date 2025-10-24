class Solution {
public:
    long long titleToNumber(string s) {
        int n = s.length();
        if(n == 1){
            return s[0] - 'A' + 1; 
        }
        long long ans = 0;
        for(int i = 0; i <= n-2 ; i++){
            ans += 26*(s[i] - 'A' + 1);
        }
        ans += s[n-1] -'A' + 1;
        return ans;
    }
};