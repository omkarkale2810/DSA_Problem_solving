class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int i = 0 ;
        int ans = 0;

        set<char> st;
        while( i < n ){
            if(st.find(s[i])!=st.end()){
                st.clear();
                ans++;
            }
            st.insert(s[i]);
            i++;
        }
        if(!st.empty()) ans++;
        return ans;

    }
};