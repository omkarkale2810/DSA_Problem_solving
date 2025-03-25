class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> sub = intervals[0];
        ans.push_back(sub);
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < ans.back()[1]) {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            } else {
                sub = intervals[i];
                ans.push_back(sub);
            }
        }
        return ans;
    }
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    bool solve(vector<vector<int>> a) {
        int start = a[0][0];
        int end = a[0][1];
        int c = 0;

        for (int i = 1; i < a.size(); i++) {
            if (end < a[i][1] && end > a[i][0]) {
                end = a[i][1];
            } else if (end == a[i][0]) {
                c++;
                end = a[i][1];
            }
        }
    return c >= 2;
    

}

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<vector<int>> x;
    vector<vector<int>> y;
    for (auto& it : rectangles) {
        x.push_back({it[0], it[2]});
        y.push_back({it[1], it[3]});
    }
    sort(x.begin(), x.end(), cmp);
    sort(y.begin(), y.end(), cmp);

    return solve(x) || solve(y);

    // sort(rectangles.begin(), rectangles.end());

    // int maxr = rectangles[0][2];
    // int c = 0;

    // for (int i = 1; i < rectangles.size(); i++) {
    //     if (rectangles[i][0] <= maxr) {
    //         c++;
    //     }
    //     maxr = max(maxr, rectangles[i][2]);
    // }

    // if (c >= 2) return true;

    // sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const
    // vector<int>& b) {
    //     return a[1] < b[1];
    // });

    // int maxu = rectangles[0][3];
    // c = 0;

    // for (int i = 1; i < rectangles.size(); i++) {
    //     if (rectangles[i][1] <= maxu) {
    //         c++;
    //     }
    //     maxu = max(maxu, rectangles[i][3]);
    // }
    // return c >= 2;
}
}
;