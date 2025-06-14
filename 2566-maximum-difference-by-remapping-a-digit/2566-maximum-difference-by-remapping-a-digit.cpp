class Solution {
public:
    int minMaxDifference(int num) {
        string no = to_string(num);
        string maxnum = no;
        string minnum = no;

        int n = no.length();
        
        char ele = 0;

        int i   = 0; 
        for(i = 0 ; i < n ; i++){
            if(maxnum[i] == '9'){
                continue;
            }
            ele = maxnum[i];
            maxnum[i] = '9';
            break;
        }  
        if( i != n-1){
            while(i < n){
                if(ele == maxnum[i]){
                    maxnum[i] = '9';
                }
                i++;
            }
        }

        i   = 0; 
        for(i = 0 ; i < n ; i++){
            if(minnum[i] == '0'){
                continue;
            }
            ele = minnum[i];
            minnum[i] = '0';
            break;
        }  
        if( i != n-1){
            while(i < n){
                if(ele == minnum[i]){
                    minnum[i] = '0';
                }
                i++;
            }
        }

        return stoi(maxnum) - stoi(minnum);
        
    }
};