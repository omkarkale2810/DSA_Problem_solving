class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        // approach 2
        vector<int> ans;
        int n = nums.size();
        
        unordered_map<int,int> mp;

        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        };
        multiset<pair<int,int>, decltype(cmp)> st(cmp);

        
        int i = 0;
        int j = 0;

        while (j < n) {
            int ele = nums[j];

            if (mp.count(ele)) {
                int pfreq = mp[ele];
                st.erase(st.find({pfreq, ele}));
                mp[ele]++;
                int nfreq = mp[ele];
                st.insert({nfreq, ele});
            } 
            else {
                mp[ele] = 1;
                st.insert({1, ele});
            }

            if (j - i + 1 >= k) {

                int sum = 0;
                int cnt = 0;

                for (auto it = st.begin(); it != st.end() && cnt < x; ++it, ++cnt) {
                    sum += 1LL * it->first * it->second;
                }
                ans.push_back(sum);

                int rem = nums[i];
                st.erase(st.find({mp[rem], rem}));
                mp[rem]--;
                if(mp[rem] == 0){
                    mp.erase(rem);
                }
                else{
                    st.insert({mp[rem], rem});
                }
                i++;
            }

            j++;
        }

        return ans;
       
        
        
        // vector<int> ans;
        // int n = nums.size();

        // for(int i = 0; i <= n - k; i++) {
        //     unordered_map<int,int> mp;
        //     for(int j = i; j < i + k; j++) {
        //         mp[nums[j]]++;
        //     }

        //     priority_queue<pair<int,int>> pq;
        //     for(auto &it : mp) {
        //         pq.push({it.second, it.first});
        //     }

        //     int sum = 0, p = 0;
        //     while(p < x && !pq.empty()) {
        //         sum += pq.top().second * pq.top().first;
        //         pq.pop();
        //         p++;
        //     }

        //     ans.push_back(sum);
        // }
        // return ans;
    }
};
