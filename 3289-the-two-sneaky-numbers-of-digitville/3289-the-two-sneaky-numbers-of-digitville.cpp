class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        map<int,int>mp;
        vector<int>ret;
        for( int n: nums)mp[n]++;
        for( auto it : mp){
            if( it.second>1){
                ret.push_back(it.first);
            }
        }
sort( ret.begin(),ret.end());
        return ret;

    }
};