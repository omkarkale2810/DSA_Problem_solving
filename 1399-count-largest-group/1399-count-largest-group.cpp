class Solution {
public:
    int countdigitsum(int n){
        if(n < 10) return n;
        int sum = 0;
        while(n > 0 ){
            int d = n%10;
            sum+=d;
            n = n/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        
        unordered_map<int,int> mp;
        int maxsize = 0;
        int c =0;

        for(int i = 1 ; i <= n ; i++){
            int sum = 0;
            sum = countdigitsum(i);
            mp[sum]++;

            if(mp[sum] == maxsize){
                c++;
            }
            else if(mp[sum] > maxsize){
                maxsize = mp[sum];
                c = 1;
            }
        }
        return c;
    }
};