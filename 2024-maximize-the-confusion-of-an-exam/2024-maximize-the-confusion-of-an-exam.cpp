class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        int n = key.size();
        
        int i = 0;
        int j = 0;

        int fc = 0;

        int maxlen = 0;
        int len = 0;

        while( j < n ){
            
            if(key[j] == 'F'){
                fc++;
            }
            len++;

            while(zc > k){
                if(key[i] == 'F'){
                    zc--;
                }
                i++;
                len--;
            }   
            if(zc <= k){
                maxlen = max(len,maxlen);
            }
            j++;
        }


        i = 0;
        j = 0;
        
        while( j < n ){
            
            if(key[j] == 'F'){
                fc++;
            }
            len++;

            while(zc > k){
                if(key[i] == 'F'){
                    zc--;
                }
                i++;
                len--;
            }   
            if(zc <= k){
                maxlen = max(len,maxlen);
            }
            j++;
        }
        return maxlen;
    }
};