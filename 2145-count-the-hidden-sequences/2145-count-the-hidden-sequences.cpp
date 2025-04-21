class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0;
        int lowval = 0;
        int maxval = 0;

        for(int &d : differences){
            curr = curr + d;
            lowval = min(lowval , curr);
            maxval = max(maxval , curr);

            if((upper-maxval)-(lower-lowval)+1 <= 0 ){
                return 0;
            } 
        }
        return (upper-maxval)-(lower-lowval)+1;
        
    }
};