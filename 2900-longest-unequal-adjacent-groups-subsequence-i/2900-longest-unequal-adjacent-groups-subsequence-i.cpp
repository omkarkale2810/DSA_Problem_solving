class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int i = 0;
        int j = 1;
        vector<string> ans;
        if(n<2){
            return words;
        }
        while( j < n ){
            if(groups[i] != groups[j]){
                ans.push_back(words[i]);
                i=j;j++;
            }else{
                j++;
            }
        }
        return ans;
    }
};