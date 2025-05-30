class Solution {
public:
    vector<vector<int>>  dir = {{0,1},{0,-1} , {1,0} ,{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int steps = 0;
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            int s = q.size();
            while(s--){            
                pair<int,int> curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                if( ( curr != make_pair(entrance[0], entrance[1]) ) &&( x == 0 || x == n-1 || y == 0 || y == m-1) ){
                    return steps;
                }
                for(auto& d: dir){
                    int newx = x + d[0];
                    int newy = y + d[1];
                    if( newx >= 0 && newx <= n-1 && newy >= 0 && newy <= m-1 && maze[newx][newy] != '+'){
                        q.push({newx,newy});
                        maze[newx][newy] = '+';
                    }
                }

            }
            steps++;
        }
        return -1;
    }
};