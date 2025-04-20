class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < answers.size() ; i++){
            mp[answers[i]]++;
        }
        int ans = 0;

        for(auto &it: mp){
            if(it.first == 0){
                ans += it.second; 
            }
            else{
                int groupSize = it.first + 1;
                int groups = ceil((double)it.second / groupSize);
                ans += groups * groupSize;
            }
        }
        return ans;
    }
};