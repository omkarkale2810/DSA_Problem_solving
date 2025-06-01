class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.length();
        long long size = 0;
        for(int i = 0 ; i < n ; i++ ){
            int ch = s[i];
            if(isalpha(ch))){
                size++;
            }
            else{
                int num = ch-'0';
                size *= num;

            }
        }

        for(int i = n-1 ; i >= 0 ; i--){
            int k = size%k;

            if(k == 0 && isalpha(s[i])){
                return s[i];
            }
            else if(isalpha(s[i])){
                size--;
            }
            else{
                size = size/(s[i]-'0');
            }
        }
        return ""



    }
};