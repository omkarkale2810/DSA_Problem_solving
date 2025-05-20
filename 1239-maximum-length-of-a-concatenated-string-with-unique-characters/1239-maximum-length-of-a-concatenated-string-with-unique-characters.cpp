class Solution {
public:
    bool isanycharduplicate(string& a , string& b){
        vector<int> hash(26,0);

        for(int i = 0 ; i < a.length() ; i++){
            if(hash[a[i] - 'a'] > 0){
                return true;
            }
            hash[a[i] - 'a']++;
        }
        for(int i = 0 ; i < b.length() ; i++){
            if(hash[b[i] - 'a'] > 0){
                return true;
            }
        }
    
        return false;

    }
    int solve(vector<string>& arr , int idx , string temp , int& n ,unordered_map<string,int>& dpmp){

        if(idx >= n){
            return temp.length();
        }
        if(dpmp.find(temp) != dpmp.end()){
            return dpmp[temp];
        }
        int take = 0;
        int nottake = 0;
        if(isanycharduplicate(arr[idx] , temp)){
            nottake = solve(arr,idx+1 , temp , n , dpmp); 
        }
        else{
            nottake = solve(arr, idx+1 , temp , n ,dpmp);
            take = solve(arr , idx+1 , temp + arr[idx] , n , dpmp);
        }
        return dpmp[temp] = max(take , nottake);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string , int> dpmp;
        return solve(arr, 0 , "" , n , dpmp);
    }
};