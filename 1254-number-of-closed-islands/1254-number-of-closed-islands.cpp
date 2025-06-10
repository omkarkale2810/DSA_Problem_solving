class Solution {
public:
    bool dfs(int i , int j , int m , int n ,vector<vector<int>>& grid, vector<vector<bool>>& visited){

        if( i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }
         if(grid[i][j] == 1 || visited[i][j]){
            return true; 
        }
        visited[i][j] = true;

        bool up  = dfs(i-1,j,m,n,grid,visited); 
        bool down = dfs(i+1,j,m,n,grid,visited);
        bool left    = dfs(i,j-1,m,n,grid,visited);
        bool right  = dfs(i,j+1,m,n,grid,visited);

        return left && right && up && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0 && visited[i][j] == false){
                    if( dfs(i,j,m,n,grid,visited) ){
                        count++;
                    }
                }
                else{
                    visited[i][j] = true;
                }
            }
        }
        return count;


    }
};