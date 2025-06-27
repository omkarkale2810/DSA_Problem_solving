class Solution {
private:
    bool check_all_zero(vector<int>& arr){
        for(int &it: arr){
            if(it!=0){
                return false;
            }
        } 
        return true;
    }
public:
    int count = 0;
    void solve(int idx, vector<vector<int>>& arr , vector<int>& resultant , int c ){
        if(idx >= arr.size()){
            if(check_all_zero(resultant)){
                count = max(c, count);
            }
            return;
        }

        int from = arr[idx][0];
        int tooo = arr[idx][1];

        resultant[from]--;
        resultant[tooo]++;
        solve(idx+1 , arr , resultant , c+1);
        resultant[from]++;
        resultant[tooo]--;
        solve(idx+1 , arr , resultant , c);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> resultant(n,0);
        int c = 0;
        solve(0 , requests , resultant , c);
        return count;
    }
};