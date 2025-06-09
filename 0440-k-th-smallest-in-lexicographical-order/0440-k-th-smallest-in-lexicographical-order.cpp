class Solution {
public:
    void dfs(long long num, int n, int k, int& count, int& result, bool& found) {
        if (num > n || found) return;

        count++;
        if (count == k) {
            result = num;
            found = true;
            return;
        }

        for (int i = 0; i <= 9; i++) {
            long long newNum = num * 10 + i;
            if (newNum > n) return;
            dfs(newNum, n, k, count, result, found);
        }
    }

    int findKthNumber(int n, int k) {
        int count = 0;
        int result = 0;
        bool found = false;

        for (int i = 1; i <= 9; i++) {
            if (found) break;
            dfs(i, n, k, count, result, found);
        }
        return result;
    }
};