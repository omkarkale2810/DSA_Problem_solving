class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        stringstream ss(s);
        string token;

        while(getline(ss , token , ' ')){
            words.push_back(token);
        }
        int ws = words.size();
        int ps = pattern.size();

        if(ws != ps){
            return false;
        }

        unordered_map<string,char> mp;
        set<char> used;
        for(int i = 0 ; i < ws ; i++){
            string word = words[i];
            char ch = pattern[i];

            if(mp.find(word) == mp.end() && used.find(ch) == used.end() ){
                mp[word] = ch;
                used.insert(ch);
            }
            else if(mp[word] != ch){
                return false;
            }

        }
        return true;
    }
};