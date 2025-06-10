class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        int n = s.length();
        for(int i = 0 ; i < n ;i++){
            freq[s[i]-'a']++;
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=  0 ; i < 26 ; i++){
            if(freq[i]!=0){
                if(freq[i]%2!=0){
                    maxi = max(maxi,freq[i]);
                }else{
                    mini = min(mini,freq[i]);
                }
            }
        }
        // if()
        return maxi-mini;

    }
};