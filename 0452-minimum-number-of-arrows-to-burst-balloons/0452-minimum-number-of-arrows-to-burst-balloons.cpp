class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int c = 1;
        int n = points.size();

        int prevs = points[0][0];
        int preve = points[0][1];

        for(int i = 1; i < n ; i++){
            if(points[i][0] <= preve){
                preve = min(preve,points[i][1]);
            }
            else{
                prevs = points[i][0];
                preve = points[i][1];
                c++;
            }
        }
        return c;
    }
};