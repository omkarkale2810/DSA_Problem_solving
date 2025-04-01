class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n <= 2)
            return true;

        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        int dy = y2 - y1;
        int dx = x2 - x1;

        for (int i = 2; i < n; i++) {
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];
            int dxi = xi - x1;
            int dyi = yi - y1;

            if (dy * dxi != dx * dyi) {
                return false;
            }
        }
        return true;
    }
};