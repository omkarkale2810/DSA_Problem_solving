class Solution {
public:
    typedef pair<long long ,int>P;
    int M = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
      unordered_map<int,vector<pair<int,int>>> adj;

        for(auto &it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<P,vector<P>, greater<P>> pq;

        vector<long long> result(n, LLONG_MAX);
        vector<int> pathc(n, 0);

        result[0] = 0;
        pathc[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){
            long long curr_time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(curr_time > result[node]) continue;  
            
            for(auto &ngbr : adj[node]){
                int ngb = ngbr.first;
                long long time = ngbr.second;

                if(curr_time + time < result[ngb]){
                    result[ngb] = curr_time + time;
                    pq.push({result[ngb], ngb});
                    pathc[ngb] = pathc[node];
                } 
                else if(curr_time + time == result[ngb]) {
                    pathc[ngb] = (pathc[ngb] + pathc[node]) % M;
                }
            }
        }

        return pathc[n-1];
    }
};