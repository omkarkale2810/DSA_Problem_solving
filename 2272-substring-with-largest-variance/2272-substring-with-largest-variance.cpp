class Solution {
public:
    int largestVariance(string s) {
        vector<int> present_alphabet(26,0);

        for(char c: s){
            present_alphabet[c-'a'] = 1;
        }

        int maxvariance = 0;

        for(char first = 'a' ; first <= 'z' ; first++){

            for(char second = 'a' ; second <= 'z' ; second++){
                if(present_alphabet[first-'a'] == 0 || present_alphabet[second-'a'] == 0){
                    continue;
                }
                int firstcount = 0;
                int secondcount = 0;
                bool flag = false;

                for(char ch : s){
                    if(ch == first){
                        firstcount++;
                    }
                    else if(ch == second){
                        secondcount++;
                    }
                    if( secondcount > 0 ){
                        maxvariance = max(maxvariance , firstcount - secondcount);
                    }
                    else if(flag){
                        maxvariance = max(maxvariance , firstcount - 1);
                    }

                    if(secondcount > firstcount){
                        secondcount = 0;
                        firstcount = 0;
                        flag = true;
                    }
                }
                
            }

        }
        return maxvariance;


    }
};