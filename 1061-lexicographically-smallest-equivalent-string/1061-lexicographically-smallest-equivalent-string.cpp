class Solution {
public:
    char dfs_min_char(unordered_map<char ,vector<char>>& adj , char curr_char ,vector<bool> &visited){
        
        visited[curr_char-'a'] = true;

        char min_char = curr_char;

        for(char& c: adj[curr_char]){

            if(visited[c-'a']==false){
                min_char = min(min_char , dfs_min_char(adj , c , visited));
            }

        }
        return min_char;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char ,vector<char>> adj;
        int n = s1.length();
        for(int i = 0 ; i < n ; i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string ans = "";
        n = baseStr.size();
        for(int i = 0 ; i < n ; i++){
            char ch = baseStr[i];
            vector<bool> visited(26,false);
            ch = dfs_min_char(adj , ch , visited);
            ans += ch; 
        }
        return ans;
    }
};