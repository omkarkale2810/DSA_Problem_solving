class Solution {
public:
    bool can_magic(int rstart, int cstart, vector<vector<int>>& grid){
        vector<bool> hash(10 , false);

        for (int i = rstart; i < rstart + 3; i++) {
            for (int j = cstart; j < cstart + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || hash[val]) {
                    return false;
                }
                hash[val] = true;
            }
        }

        for (int i = 0; i < 3; i++) {
            int row_sum = grid[rstart + i][cstart] + grid[rstart + i][cstart + 1] + grid[rstart + i][cstart + 2];
            if (row_sum != 15) return false;
        }

        for (int j = 0; j < 3; j++) {
            int col_sum = grid[rstart][cstart + j] + grid[rstart + 1][cstart + j] + grid[rstart + 2][cstart + j];
            if (col_sum != 15) return false;
        }

        int diag1 = grid[rstart][cstart] + grid[rstart + 1][cstart + 1] + grid[rstart + 2][cstart + 2];
        int diag2 = grid[rstart][cstart + 2] + grid[rstart + 1][cstart + 1] + grid[rstart + 2][cstart];
        if (diag1 != 15 || diag2 != 15) return false;

        return true;
    
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if( m < 3 || n < 3){
            return 0;
        }
        int c = 0;

        for(int i = 0 ;i <= m-3 ; i++){
            for(int j = 0 ; j <= n-3 ; j++){
                if(can_magic(i,j ,grid)){
                    c++;
                }
            }
        }
        return c;
    }
};