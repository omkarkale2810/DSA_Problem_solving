class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi = 0;
        int n = points.size();
        if(n==1) return 1;

        for( int i = 0 ; i < n ; i++){
            for( int j = i+1 ; j < n ; j++){
                int c = 2;
                int d1x = (points[i][0] - points[j][0]);
                int d1y = (points[i][1] - points[j][1]);
                double slope_first;
                if(d1x == 0){
                    slope_first = 1e9;
                }
                else{
                    slope_first = (double)d1y/d1x;
                }

                for(int k = 0 ; k < n ; k++){
                    if( k == i || k == j ){
                        continue;
                    }
                    int d2y = (points[j][1] - points[k][1]);
                    int d2x = (points[j][0] - points[k][0]);
                    double slope_second = 0;
                    
                    if(d2x == 0){
                        slope_second = 1e9;
                    }
                    else{
                        slope_second = (double)d2y/d2x;
                    }
                    if (fabs(slope_first - slope_second) < 1e-9) { // Floating point comparison
                        c++;
                    } 
                }
                maxi = max(maxi , c);
            }
        }
        return maxi;

    }
};