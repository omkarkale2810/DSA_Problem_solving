class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        queue<int> qu;
        qu.push(0);
        int jumps = 0;
        vector<bool> visited(n+1,false);
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]].push_back(i);
        }

        while(!qu.empty()){
            int size = qu.size();

            while(size--){
                int curr = qu.front();
                qu.pop();

                int ele = arr[curr];
                visited[curr] = true; 

                if(curr == n-1){
                    return jumps;
                }
                if(curr - 1 >= 0 && visited[curr-1] == false){
                    qu.push(curr-1);
                }
                if(curr + 1 < n && visited[curr+1] == false){
                    qu.push(curr+1);
                }
                if(mp[ele].size() != 0){
                    while(mp[ele].size() != 0){
                        int id = mp[ele].back();
                        mp[ele].pop_back();
                        if(visited[id] == false){
                            qu.push(id);
                        }
                    }
                }
            }
            jumps++;
        }
        return n-1;
    }
};