class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
        return;
    }
    
    vector<vector<int>> getIntervals() {
        vector<int> interval(st.begin(),st.end());
        int n = interval.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n ; i++){
            int start = interval[i];
            while(i+1 < n && interval[i+1]-1 == interval[i]){
                i++;
            }
            int end = interval[i];
            ans.push_back({start,end});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */