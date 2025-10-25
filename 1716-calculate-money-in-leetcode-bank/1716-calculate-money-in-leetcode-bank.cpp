class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;

        int con = 1;
        int bal = 1;
        
        int day = 0;
        for(int i = 0; i < n; i++){
            if(day == 7){
                day = 0;
                con++;
                bal = con; 
            }

            ans += bal;
            bal++;
            day++;
        }
        return ans;
    }
};