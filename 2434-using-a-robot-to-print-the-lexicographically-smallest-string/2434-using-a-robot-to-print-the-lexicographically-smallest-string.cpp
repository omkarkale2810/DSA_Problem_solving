class Solution {
public:
    string robotWithString(string s) {
        string p = "";

        int n = s.length();
        vector<char> rightsmall(n);
        rightsmall[n-1] = s[n-1];
        for(int i = n-2; i >= 0 ;i--){
            rightsmall[i] = min(s[i] ,rightsmall[i+1]);
        }
        stack<char> t;
        for(int i  = 0 ; i < n ; i++){
            t.push(s[i]);
            char right_minchar = i+1 < n ? rightsmall[i+1] : s[i];

            while(!t.empty() && right_minchar >= t.top()){
                p += t.top();
                t.pop();
            }
        }
        while(!t.empty()){
            p += t.top();
            t.pop();
        }
        return p;
    }
};