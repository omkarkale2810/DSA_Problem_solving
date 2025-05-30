class Solution {
public:
    void dfs(unordered_map<int , vector<int>> &adj , vector<vector<int>>& result , vector<int>& temp , int start , int goal){
        temp.push_back(start);
        if( start == goal ){
            result.push_back(temp);
        }
        else{
            for(auto &ngbr : adj[start]){
                dfs(adj,result,temp,ngbr,goal);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp;
        int n = graph.size();
        unordered_map<int , vector<int>> adj;
        for(int i = 0 ; i < n ; i++){
            adj[i] = graph[i];
        }
        dfs(adj, result , temp , 0 , n-1);
        return result;
    }
};