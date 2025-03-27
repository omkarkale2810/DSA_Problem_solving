class Solution {
public:
    // Bruteforce is O(n^3)
    // completed in 52ms
    // beats 18.83% user
    int bruteforce(vector<vector<int>>& points){
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
    int maxPoints(vector<vector<int>>& points) {
        // return bruteforce(points);

        int n = points.size();
        if( n == 2 || n == 1){
            return n;
        }
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            unordered_map<double,int>mp; 
            for(int j = 0 ; j < n ; j++){
                if(i == j) continue;
                double slope;
                int dx = (points[i][0] - points[j][0]);
                int dy = (points[i][1] - points[j][1]);
                double angle = atan2(dy,dx);
                mp[angle]++; 
            }
            for(auto &it :mp){
                maxi = max(maxi , it.second+1);

            }
        }
        return maxi;
    }
};