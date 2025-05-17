class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if(m!=n) return 0;
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        for(int i = 0 ; i< 26 ;i++){
            if((f1[i] == 0 && f2[i] == 0) || (f1[i]!=0 &&f2[i]!=0)){
                continue;
            }
            return false;
        }
        for(int i = 0 ; i < m ; i++){
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        return f1==f2;
    }
};