class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;

        for(string & st : words){
            string res = "";
            for(char & ch : st){
                if(ch != separator){
                    res += ch;
                }
                else{
                    if(res.size() > 0){
                        ans.push_back(res);
                        res = "";
                    }
                }

            }
            if(res.size() > 0){
                ans.push_back(res);
            }

        }
        return ans;
    }
};