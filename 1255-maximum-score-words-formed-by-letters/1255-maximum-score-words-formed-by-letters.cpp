class Solution {
public:
    void backtrack(int idx, int curr,vector<string>& words, vector<int>& hash, vector<int>& score, int& ans ){
        if(curr > ans){
            ans = curr;
        }
        if(idx >= words.size()){
            return;
        }

        vector<int> temphash = hash;

        int j         = 0;
        int tempscore = 0;

        while(j < words[idx].length()) {
            char ch = words[idx][j];

            temphash[ch - 'a']--;
            tempscore += score[ch - 'a'];

            if(temphash[ch-'a'] < 0)
                break;

            j++;
        }

        if(j == words[idx].length()){
            backtrack(idx + 1, curr + tempscore, words, temphash, score, ans); 
        }

        backtrack(idx+1, curr, words, hash, score, ans);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> hash(26 , 0);

        for(char& ch: letters){
            hash[ch-'a']++;
        }
        int maxscore  = 0;
        int currscore = 0; 
        backtrack(0, currscore, words, hash, score, maxscore);    
        return maxscore;
    }
};