class Solution {
public:
    bool isallzero(vector<int>& hash){
        for(int i = 0 ; i < 128 ; i++){
            if(hash[i] > 0) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = t.length();

        if( n > s.length()){
            return "";
        }

        vector<int> hash(128, 0);

        for(char& ch: t){
            hash[ch]++;
        }


        string ans = "";

        int i = 0;
        int j = 0;
        int len = s.length();
        int minlen = len+1;

        while( j < s.length()){
            hash[s[j]]--;

            while( j - i + 1 >= n && isallzero(hash)){
                len =  j - i + 1;
                if(len < minlen){
                    ans = s.substr(i , j-i+1);
                    minlen = len;
                }
                hash[s[i]]++;
                i++;
            }
            
            j++;
        }
        return ans;

    }
};