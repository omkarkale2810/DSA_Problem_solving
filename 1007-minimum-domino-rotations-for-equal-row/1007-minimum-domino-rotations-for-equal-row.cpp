class Solution {
public:
    int findswaps(vector<int>& tops , vector<int>& bottoms , int val){
        int topc = 0, bottc = 0;
        for(int i = 0 ; i < tops.size(); i++){
            if(tops[i] != val && bottoms[i] != val){
                return -1;
            }
            else if(tops[i] != val ){
                topc++;
            }
            else if(bottoms[i]!= val){
                bottc++;
            }
        }
        return min(topc,bottc);

    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;

        for(int val = 1 ; val <= 6 ; val++){
            int swap = findswaps(tops,bottoms,val);
            if(swap != -1){
                result = min(result , swap);
            }
        }
        return result == INT_MAX ? -1:result;
    }
};