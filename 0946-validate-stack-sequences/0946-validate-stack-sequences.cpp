class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();

        stack<int> st;
        int j  = 0;
        for(int i = 0 ; i < n ; i++){
            st.push(pushed[i]);

            while(!st.empty() && j < n && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }

        return j == n;
    }
};