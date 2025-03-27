class Solution {
public:
    typedef pair<int,int> P;  
    int val_of_equation_of_slope(P p1, P p2 ,P p3){
        int x1 = p1.first;
        int y1 = p1.second;
        int x2 = p2.first;
        int y2 = p2.second;
        int x3 = p3.first;
        int y3 = p3.second;
        return ((y3-y2)*(x2-x1) - (y2-y1)*(x3-x2)); 
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin() , trees.end());
        int n = trees.size();
        if( n <= 3) return trees;

        deque<pair<int,int>> upper, lower;

        for(auto &point: trees){
            int ls = lower.size();
            int us = upper.size();

            while(ls >= 2 && (val_of_equation_of_slope(lower[ls-2], lower[ls-1] , {point[0] , point[1]}) < 0) ){
                ls--;
                lower.pop_back();
            }
            
            while(us >= 2 && (val_of_equation_of_slope(upper[us-2], upper[us-1] , {point[0] , point[1]}) > 0) ){
                us--;
                upper.pop_back();
            }
            lower.push_back({point[0] , point[1]});
            upper.push_back({point[0] , point[1]});
        }

        set<P> st;
        for(auto & point : upper){
            st.insert(point);
        }
        
        for(auto & point : lower){
            st.insert(point);
        }

        vector<vector<int>> result;
        for( auto &it: st){
            result.push_back({it.first,it.second});
        }
        return result;

        
    }
};