class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();


        unordered_map<int, vector<int>> mp;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto &it: mp){
            int key = it.first;
            if(key < 0){
                sort(mp[key].begin(), mp[key].end());
            }
            else{
                sort(mp[key].rbegin(), mp[key].rend());
            }
        }

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                int key = i-j;
                grid[i][j] = *mp[key].begin();
                mp[key].erase(mp[key].begin());
            }
        }

        return grid;
    }
};