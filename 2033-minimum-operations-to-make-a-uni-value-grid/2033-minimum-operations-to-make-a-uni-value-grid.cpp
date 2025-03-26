class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0 ; i < n  ; i++){
            for(int j = 0 ; j < m ; j ++){
                arr.push_back(grid[i][j]);
            }
        }
        int l = arr.size();
        sort(arr.begin() , arr.end() );
        int target = arr[(l/2)];
        int c = 0;

        for(int i = 0 ; i < l ; i++){
            if(arr[i] % x  != target % x ){
                return -1;
            }
            c += abs(target - arr[i])/x ;
        }

        return c;


    }
};