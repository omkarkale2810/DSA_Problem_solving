class Solution {
public:
    bool isvowel(char &ch){
        return (ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u'); 
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        
        int ans = 0;
        int len = 0;

        int i = 0;
        int j = 0;

        while( j < n ){
            if(isvowel(s[j])){
                len++;
            }

            if( j - i + 1 == k){
                ans = max(ans, len);
                if(isvowel(s[i])){
                    len--;
                }
                i++;
            }
            j++;
        }

        return ans;

    }
};