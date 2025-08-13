class Solution {
public:
    vector<vector<int>> dir = {{-1,-1} , {-1,0} , {-1, 1} , { 0, -1} , { 0 , 1} , {1,-1} , {1,0} , {1, 1}};
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> ans(row, vector<int>(col , 0));

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                int live = 0;
                for(auto& vec : dir){
                    int i_ = i + vec[0];
                    int j_ = j + vec[1];

                    if( i_ >= 0 && i_ < row && j_ >= 0 && j_ < col){
                        if(board[i_][j_] == 1){
                            live++;
                        }
                    }
                } 

                if(board[i][j] == 1 && live < 2){
                    ans[i][j] = 0;
                }
                else if(board[i][j] == 1 && (live == 2 || live == 3)){
                    ans[i][j] = 1;
                }
                else if(board[i][j] == 1 && live > 3){
                    ans[i][j] = 0;
                }
                else if(board[i][j] == 0 && live == 3){
                    ans[i][j] = 1;
                }

            }
        }
        board = ans;

    }
};