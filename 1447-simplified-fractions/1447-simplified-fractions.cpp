class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        unordered_set<float> st;
        for(int i = 1; i < n ; i++){
            for(int j = i+1; j <= n; j++){
                if(st.find((float)i/j) == st.end()){
                    string curr = to_string(i) + '/' + to_string(j);
                    ans.push_back(curr);
                    st.insert((float)i/j);
                }
            }
        }
        return ans;
    }
};