class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j = 0;
        stack<int> st;
        int ts= target.size();

        for(int i = 1 ; i <= n ; i++){
            
            st.push(i);

            if( j < ts && st.top()==target[j]){
                ans.push_back("Push");
                j++;
                
            }
            else{
                st.pop();
                ans.push_back("Push");
                ans.push_back("Pop");
            }

            if(j >= ts){
                break;
            }
            
        }   
        return ans;
    }
};