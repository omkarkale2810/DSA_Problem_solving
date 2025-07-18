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

            while(fc > k){
                if(key[i] == 'F'){
                    fc--;
                }
                i++;
                len--;
            }   
            if(fc <= k){
                maxlen = max(len,maxlen);
            }
            j++;
        }


        i = 0;
        j = 0;
        len = 0;

        int tc = 0;

        while( j < n ){
            
            if(key[j] == 'T'){
                tc++;
            }
            len++;

            while(tc > k){
                if(key[i] == 'T'){
                    tc--;
                }
                i++;
                len--;
            }   
            if(tc <= k){
                maxlen = max(len,maxlen);
            }
            j++;
        }

        return maxlen;
    }
};