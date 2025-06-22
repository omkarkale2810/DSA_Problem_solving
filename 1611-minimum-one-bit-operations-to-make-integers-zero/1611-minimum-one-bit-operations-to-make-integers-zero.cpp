class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0){
            return 0;
        }
        vector<long long> func(32,0);

        func[0] = 1;
        for(int i = 1 ; i <= 31 ;i++){
            func[i] = 2*func[i-1] + 1;
        }
        int result = 0;
        int sign   = 1;

        for(int i = 30 ; i>= 0 ;i--){
            
            int ithbit = ((1 << i)&n);

            if(ithbit == 0){
                continue;
            }
            if(sign > 0){
                result += func[i];
            }
            else{
                result -= func[i];
            }
            sign = -1*sign;
        }
        return result;
    }
};