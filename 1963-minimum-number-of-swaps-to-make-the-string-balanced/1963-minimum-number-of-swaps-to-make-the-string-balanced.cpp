class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();

        int step = 0;
        int close = 0;
        int open  = 0;

        for(int i = 0 ; i < n ; i ++){
            if(s[i] == '['){
                open++;
            }
            else if(s[i] == ']'){
                close++;
            }
            if(close > open){
                step++;
                close--;
                open++;
            }
        }
        return step;
        
    }
};