class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int max_ele = *max_element(arr.begin() , arr.end());
        if( k >= n){
            return max_ele;
        }
        int curr_win = arr[0];
        int streak = 0;
        for(int i = 1 ; i < n ; i++){
            if(streak == k || curr_win == max_ele){
                return curr_win;
            }
            if(arr[i] > curr_win){
                curr_win = arr[i];
                streak = 1;
            }
            else  if(arr[i] < curr_win){
                streak++;
            }
        }
        return max_ele;
    }
};