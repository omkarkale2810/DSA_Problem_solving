class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s1 = 0;
        int s0 = 0;

        for(int& it: students){
            if(it == 0){
                s0++;
            }
            else{
                s1++;
            }
        }
        int n = sandwiches.size();
        for(int i = 0 ; i < n ; i++){
            if(sandwiches[i] == 1 && s1 > 0){
                s1--;
            }
            else if(sandwiches[i] == 1 && s1 == 0){
                return n-i;
            }
            if(sandwiches[i] == 0 && s0 > 0){
                s0--;
            }
            else if(sandwiches[i] == 0 && s0 == 0){
                return n-i;
            }
        }
        return 0;
    }
};