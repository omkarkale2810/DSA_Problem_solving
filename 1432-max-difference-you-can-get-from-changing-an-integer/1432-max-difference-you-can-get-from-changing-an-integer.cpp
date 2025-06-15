class Solution {
public:
    int maxDiff(int num) {
        string no = to_string(num);
        string maxnum = no;
        string minnum = no;

        int n = no.length();
        
        char ele = 0;

        int i    = 0; 
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

        bool flag = false;
        i   = 0; 
        for(i = 0 ; i < n ; i++){
            if(minnum[i] == '1'){
                flag = true;
                continue;
            }
            if(flag){
                ele = minnum[i];
                minnum[i] = '0';
                break;    
            }
            ele = minnum[i];
            minnum[i] = '1';
            break;
        }  
        if( i != n-1){
            while(i < n){
                if(ele == minnum[i] && flag==false){
                    minnum[i] = '1';
                }
                else if(ele == minnum[i] && flag){
                    minnum[i] = '0';
                }
                
                i++;
            }
        }

        return stoi(maxnum) - stoi(minnum);
    }
};