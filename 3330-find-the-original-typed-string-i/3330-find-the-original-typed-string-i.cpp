#include <string>

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1;
        
        char prev = word[0];
        int c = 1;
        for(int i = 1; i < word.length()  ; i++){
            
            while(i < word.length() && word[i] == prev){
                c++;
                i++;
            }
            if(c > 1){
                ans += (c-1);
            }
            c = 1;
            prev = word[i];
        }
      
        return ans;
    }
};
