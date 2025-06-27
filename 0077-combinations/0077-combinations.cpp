class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<int> st;
    void backtrack(int ele, vector<int>& curr , int &n , int k){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        for(int i = ele; i <= n ; i++){
            if(st.find(i) == st.end()){
                curr.push_back(i);
                st.insert(i);
                backtrack(i , curr , n , k );
                curr.pop_back();
                st.erase(i);
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(1,curr,n , k);
        return ans;
    }
};