class Solution {
public:
    vector<int> LSS(vector<int>& arr , int& n){
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n ; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = -1;
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> RSS(vector<int>& arr , int& n){
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1 ; i >= 0  ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = n;
            }
            st.push(i);
        }
        return ans;

    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        long long maxarea = 0;

        vector<int> lss = LSS(heights , n);
        vector<int> rss = RSS(heights , n);
        
        for(int i = 0 ; i < n ; i++){
            long long area = 0;
            long long w = rss[i] - lss[i] - 1 ;
            area = w * heights[i];
            maxarea = max(area , maxarea);
        }

        return maxarea;
    }
};