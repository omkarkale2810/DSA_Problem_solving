class Solution {
public:
    bool isvalid(vector<vector<int>>& board, int row, int col) {
        
        for(int i = row; i>=0; i--) {
            if(board[i][col] == 1)
                return false;
        }
        for(int i = row, j = col; i>=0 && j >= 0; i--, j--) {
            if(board[i][j] == 1)
                return false;
        }
        for(int i = row, j = col; i>=0 && j<board.size(); i--, j++) {
            if(board[i][j] == 1)
                return false;
        }
        return true;
    }
    void solve(int row, vector<vector<int>>& board, int &ans, int& n){
        if(row == n){
            ans++;
            return;
        }

        for(int i = 0 ; i < n ; i++){

            if(isvalid(board, row, i)){
                board[row][i] = 1;
                solve(row+1, board, ans, n);
                board[row][i] = 0;
            }
            
        }


    }

    int totalNQueens(int n){
        vector<vector<int>> board(n, vector<int>(n , 0));
        int ans = 0;
        solve(0, board, ans, n);
        return ans;
    }
};