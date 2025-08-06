class Solution {
public:
    void build_segment_tree(int idx, int l, int r, vector<int>& segtree, vector<int>& baskets) {
        if (l == r) {
            segtree[idx] = baskets[l];
            return;
        }

        int mid = (l + r) / 2;

        build_segment_tree(2 * idx + 1, l, mid, segtree, baskets);
        build_segment_tree(2 * idx + 2, mid + 1, r, segtree, baskets);

        segtree[idx] = max(segtree[2*idx+1], segtree[2*idx+2]);
    }

    bool query_segment_tree(int idx, int l, int r, int fruit, vector<int>& segtree){
        if(segtree[idx] < fruit){
            return false;
        }

        if(l == r){
            segtree[idx] = -1;
            return true;
        }

        int mid = (l + r)/2;
        bool placed = false;

        if(fruit <= segtree[2*idx + 1]){
            placed = query_segment_tree(2*idx + 1, l, mid, fruit, segtree);
        }
        else{
            placed = query_segment_tree(2*idx + 2, mid+1, r, fruit, segtree);
        }

        segtree[idx] = max(segtree[2*idx + 1] , segtree[2*idx + 2]);
        return placed;

    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        vector<int> segtree(4*n, -1);
        int unplaced = 0;

        build_segment_tree(0, 0, n-1, segtree, baskets);

        for(int &fruit: fruits){
            if(query_segment_tree(0, 0, n-1, fruit, segtree) == false){
                unplaced++;
            }
        }
        return unplaced;
    }
};