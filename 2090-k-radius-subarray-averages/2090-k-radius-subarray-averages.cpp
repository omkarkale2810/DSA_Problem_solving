class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n , -1);
        vector<long long> arr(nums.begin(),nums.end());
        for(int i = 1 ; i < n ; i++){
            arr[i] = arr[i-1]+arr[i];
        }

        for(int i = k; i < n - k ; i++){
            int sum = arr[i+k];
            if( i-k-1 >= 0 ){
                sum -= arr[i-k-1];
            }
            ans[i] = sum/(2*k+1);
        }
        return ans;
    }
};