class Solution {
public:
    vector<int> generaterow(int row){
        long long ele = 1;
        vector<int> ans;
        ans.push_back(ele);
        for(int col = 1 ; col < row ; col++){
            ele = ele*(row-col);
            ele=ele/col;
            ans.push_back(ele);
        }
        return ans; 
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int row = 1 ; row <= numRows ; row++){
            ans.push_back(generaterow(row));
        }
        return ans;
    }
};