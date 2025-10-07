class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int , int> full;
        set<int> dry;
        
        int n = rains.size();
        vector<int> res(n , 1);
        
        for(int i = 0; i < n; i++){
            
            if(rains[i] > 0){
                int lake = rains[i];
                
                if(full.count(lake) > 0){
                    auto it = dry.lower_bound(full[lake]);
                    if (it == dry.end()) return {};
                    res[*it] = lake;
                    dry.erase(it);
                }

                full[lake] = i;
                res[i] = -1;
            
            } 
            else{
                dry.insert(i);
            }
        }
        return res;
    }
};