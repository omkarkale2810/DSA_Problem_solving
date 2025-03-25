class Solution {
public:
    vector<vector<string>> result;
    bool isValid(vector<string>& board, int row, int col) {
        //look for up
        for(int i = row; i>=0; i--) {
            if(board[i][col] == 'Q')
                return false;
        }
        
        //check left diagonal upwards
        for(int i = row, j = col; i>=0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }
        
        //check right diagonal upwards
        for(int i = row, j = col; i>=0 && j<board.size(); i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solve(vector<string>& board, int row) {
        if(row == board.size()) {
            result.push_back(board);
            return;
        }
        for(int i = 0; i<board.size(); i++) {
            if(isValid(board, row, i)) {
                board[row][i] = 'Q';
                
                solve(board, row+1);
                
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)
            return {};
        vector<string> board(n, string(n, '.')); 
        
        solve(board, 0);
        
        return result;
    }
};













// class Solution {
// public:
//     void addsolution_to_string(int n , vector<vector<int>>& board, vector<vector<string>>& ans){
//         vector<string> temp;  
//         for(int i = 0 ; i < n ; i++){
//             string row = "";
//             for(int j = 0 ; j < n ; j++){
//                 if(board[i][j] == 1)
//                     row += "Q";
//                 else
//                     row += ".";
//             }
//             temp.push_back(row);
//             ans.push_back(temp);  
//         }
       
//     }

//     bool isqueensafe(int row , int col , int n , vector<vector<int>>& board ){
//         int x = row;
//         int y = col;
//         while(x >= 0 && y >= 0){
//             if(board[x][y] == 1){
//                 return false;
//             }
//             x--;
//             y--;
//         }

//         x = row;
//         y = col;

//         while(x < n && y >= 0){
//             if(board[x][y] == 1){
//                 return false;
//             }
//             x++;
//             y--;
//         }

//         for(int i = 0; i < row; i++){
//             if(board[i][col] == 1){
//                 return false;
//             }
//         }

//         return true;
//     }

//     void solve(int col , int n , vector<vector<int>>& board , vector<vector<string>>& ans){
//         if(col == n){
//             addsolution_to_string(n,board,ans);
//             return;
//         }

//         for(int row = 0 ; row < n ; row++){
//             if(isqueensafe(row,col,n,board)){
//                 board[row][col] = 1;
//                 solve(col+1 , n , board , ans);
//                 // backtrack sathi board clean
//                 board[row][col] = 0;
//             }   

//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<vector<int>> board(n , vector<int>(n,0));

//         solve( 0 , n , board , ans);
//         return ans;
        
//     }
// };