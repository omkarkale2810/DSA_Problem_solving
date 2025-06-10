class Solution {
public:
    int M;
    int N;
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs_mark(int i , int j , vector<vector<int>>& grid){
        if( i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        for(auto& dir:dirs){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            dfs_mark(new_i,new_j,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        M = m;
        N = n;
        int c = 0;
        for(int j = 0 ; j < n ;j++){
            if(grid[0][j] == 1){
                dfs_mark(0,j,grid);
            }
        }
        for(int j = 0 ; j < n ;j++){
            if(grid[m-1][j] == 1){
                dfs_mark(m-1,j,grid);
            }
        }
        for(int j = 0 ; j < m ;j++){
            if(grid[j][0] == 1){
                dfs_mark(j,0,grid);
            }
        }
        for(int j = 0 ; j < m ;j++){
            if(grid[j][n-1] == 1){
                dfs_mark(j,n-1,grid);
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    c++;
                }
            }
        }
        return c;
    }
};