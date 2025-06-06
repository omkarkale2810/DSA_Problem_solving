class Solution {
public:
   void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<int> rowarr(m, 0); 
    vector<int> columnarr(n, 0); 

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                rowarr[i] = 1;
                columnarr[j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rowarr[i] == 1 || columnarr[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}
};