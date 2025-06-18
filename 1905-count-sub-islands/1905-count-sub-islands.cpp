class Solution {
public:
    int m = 0;
    int n = 0;
    bool dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<bool>> &visited ){
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true || grid2[i][j]==0){
            return true;
        }

        visited[i][j] = true;

       bool issubisland = (grid1[i][j] == 1);

        issubisland &= dfs(i + 1, j, grid1, grid2, visited);
        issubisland &= dfs(i - 1, j, grid1, grid2, visited);
        issubisland &= dfs(i, j + 1, grid1, grid2, visited);
        issubisland &= dfs(i, j - 1, grid1, grid2, visited);

        return issubisland;

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid2.size();
        n = grid2[0].size();
        int c = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid2[i][j] == 1 && visited[i][j] == false){
                    if(dfs(i , j , grid1 , grid2 , visited)){
                        c++;
                    }
                }
            }
        }
        return c;
    }
};