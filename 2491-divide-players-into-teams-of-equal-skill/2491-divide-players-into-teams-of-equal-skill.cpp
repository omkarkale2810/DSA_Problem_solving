class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(begin(skill),end(skill));
        int i = 0;
        int j = n-1;
        int s = skill[j] + skill[i];
        long long ans  = 0; 
        while( j > i ){
            if(skill[j] + skill[i] == s){
                ans += skill[i]*skill[j];
                i++;
                j--;
            }
            else{
                return -1;
            }

        }
        return ans;
    }
};