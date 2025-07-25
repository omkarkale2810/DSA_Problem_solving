class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        int n = nums.size();
        for(int i = 0; i < n ; i++){
            int start = nums[i];
            int end   = nums[i];
            while( i+1 < n && nums[i] + 1 == nums[i+1]){
                end = nums[i+1];
                i++;
            }

            if(start != end){
                ans.push_back(to_string(start) + "->" + to_string(end)); 
            }
            else{
                ans.push_back(to_string(start));
            }
        }
        return ans;
        
    }
};