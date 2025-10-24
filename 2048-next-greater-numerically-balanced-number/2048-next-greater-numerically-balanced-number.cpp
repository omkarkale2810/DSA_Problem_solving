class Solution {
public:
    bool isbeauty(int n){
        vector<int> hash(10, 0);

        while(n > 0){
            int ele = n%10;
            hash[ele]++;
            n = n/10;
        }

        for(int i = 0 ; i < 10; i++){
            if(hash[i] != 0 && hash[i] != i){
                return false;
            }
        }
        return true;

    }
    int nextBeautifulNumber(int n) {
        int nxt = n+1;

        while(1){
            if(isbeauty(nxt)){
                break;
            }
            nxt++;
        }
        return nxt;
    }
};