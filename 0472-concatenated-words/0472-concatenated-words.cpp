class Solution {
public:
    unordered_map<string,bool> dp;
    bool isconcatinated(string word , unordered_set<string>& st){
        int n = word.length();
        if(dp.find(word) != dp.end()){
            return dp[word];
        }

        for(int i = 0 ; i < n ; i++){
            
            string prefix = word.substr(0,i+1);
            string suffix = word.substr(i+1);

            if( ( st.find(prefix) != st.end() && st.find(suffix) != st.end() ) || ( st.find(prefix) != st.end() && isconcatinated(suffix , st) )  ){
                return dp[word] =  true;
            }
        }
        return dp[word] = false;

    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        unordered_set<string> st(words.begin(),words.end());
        vector<string> ans;
        for(int i = 0 ; i < n ; i++){
            string word = words[i];
            
            if(isconcatinated(word , st)){
                ans.push_back(word);
            }
        }
        return ans;

    }
};