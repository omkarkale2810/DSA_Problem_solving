class Solution {
public:
    string result = "";
    void solve(string curr, int n, int &k, vector<bool>& hash){
        if(curr.size() == n){
            k--;
            if(k == 0){
                result = curr;
            }
            return;
        }
        for(int i = 1 ; i <= n ; i++)   {
            if(hash[i] == false){
                hash[i] = true;
                curr += to_string(i); 
                solve(curr , n , k, hash);
                hash[i] = false;
                curr.pop_back();
            }
        }

    }
    string getPermutation(int n, int k) {
        vector<bool> hash(n+1,false);

        solve("", n, k, hash);
        return result;
    }
};