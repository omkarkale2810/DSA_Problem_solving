#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    int bfs(vector<vector<int>>& grid, int key , int row , int col) {
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // Min-heap
        int count = 0;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto& curr = pq.top();
            int ele = curr[0], i = curr[1], j = curr[2];
            pq.pop();

            if (ele >= key) break;  // Stop exploring if value exceeds key
            count++;

            for (auto& it : dir) {
                int newi = i + it[0], newj = j + it[1];
                if (newi >= 0 && newj >= 0 && newi < row && newj < col && !visited[newi][newj] && grid[newi][newj] < key) {
                    visited[newi][newj] = true;
                    pq.push({grid[newi][newj], newi, newj});
                }
            }
        }
        return count;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int row = grid.size(), col = grid[0].size(), n = queries.size();
        vector<int> result;
        result.reserve(n);  

        for (int i = 0; i < n; i++) {
            result.push_back(bfs(grid, queries[i], row, col));
        }
        return result;
    }
};
