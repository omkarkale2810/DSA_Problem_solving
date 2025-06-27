class Solution {
public:

    void backtrack(int idx, string& curr, unordered_map<char,string>& mp , string& digit , vector<string> &ans){\
        if(curr.size() == digit.size()){
            ans.push_back(curr);
            return;
        }
        if(idx >= digit.size()){
            return;
        }
        for(char &it: mp[digit[idx]]){
            curr.push_back(it);
            backtrack(idx+1 , curr , mp , digit , ans  );
            curr.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0){
            return {};
        }
        
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string curr ="";
        backtrack(0 , curr , mp , digits , ans);
        return ans;
    }
};