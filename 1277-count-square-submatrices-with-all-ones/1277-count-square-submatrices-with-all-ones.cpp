class Solution {
public:
    // void help(vector<int>& row, int& count, int &n){
    //     int i = 0;
    //     int j = 0;
    //     while( i < n ){
    //         if(row[i] == 0){
    //             i++;
    //             j = i;
    //             continue;
    //         }
    //         while(j < n && row[i] == row[j]){
    //             if(row[i] == (j-i+1)){
    //                 if(i != j){
    //                     count += 1;
    //                 }
    //             }   
    //             j++;
    //         }
    //         i++;
    //         j = i;
    //     }
    // }


    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int count = 0;
        
        for(int i = 1 ;  i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(matrix[i][j]==1){
                    matrix[i][j] += min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]});
                }
            }
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                count += matrix[i][j];
            }
        }
        return count;
    }
};