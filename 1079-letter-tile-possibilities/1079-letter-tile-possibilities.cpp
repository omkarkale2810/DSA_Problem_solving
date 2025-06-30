class Solution {
public:
    unordered_set<string> st;

    void backtrack(string& curr, vector<int>& hash) {
        st.insert(curr);
        for (int i = 0; i < 26; i++) {
            if (hash[i] == 0) continue;

            hash[i]--;
            curr.push_back(i + 'A');
            backtrack(curr, hash);
            curr.pop_back();
            hash[i]++;
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> hash(26, 0);
        for (char ch : tiles) {
            hash[ch - 'A']++;
        }

        string curr;
        backtrack(curr, hash);
        return st.size() - 1;
    }
};