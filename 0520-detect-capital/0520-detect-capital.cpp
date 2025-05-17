class Solution {
public:
    bool detectCapitalUse(string word) {
        int cc = 0;
        int n = word.size();
        for(char & ch : word ){
            if(isupper(ch)){
                cc++;
            }
        }
        if( cc == n || cc == 0 || (cc == 1 && isupper(word[0]) ) )
        return true;
        return false;

    }
};