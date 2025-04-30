class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for(int &num: nums){
            int no_of_digit = log10(num)+1;
            if(no_of_digit%2 == 0){
                c++;
            }
        }
        return c;
    }
};