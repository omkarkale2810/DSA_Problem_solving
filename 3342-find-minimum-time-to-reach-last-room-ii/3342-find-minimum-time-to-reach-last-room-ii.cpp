class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dijkstra_algo(vector<vector<int>>& matrix , int m , int n){

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0;

        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();

            int t = curr[0];
            int i = curr[1];
            int j = curr[2];

            if(i == m-1 && j == n-1){
                return t;
            }  

            for(auto &it: dir){
                int new_i = i + it[0];
                int new_j = j + it[1];
               
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                    int wait = max(matrix[new_i][new_j] - t, 0);
                    int movecost = (new_i+new_j)%2 == 0?2:1;
                    int arrTime = t + wait + movecost;

                    if(result[new_i][new_j] > arrTime) {
                        result[new_i][new_j] = arrTime;
                        pq.push({arrTime, new_i, new_j});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        return dijkstra_algo(moveTime, m, n);
    }
};