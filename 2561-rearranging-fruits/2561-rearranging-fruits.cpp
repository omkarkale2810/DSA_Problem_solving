class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // unordered_map<int, int> mp1;
        // unordered_map<int, int> mp2;

        // for(int& it: basket1){
        //     mp1[it]++;
        // }
        // for(int& it: basket2){
        //     mp2[it]++;
        // }

        // int cost = 0;

        // sort(basket1.begin(), basket1.end());
        // sort(basket2.begin(), basket2.end());

        // int i = 0;
        // int j = 0;
        // bool flag = false;
        // while( i < basket1.size() && j < basket2.size()){
        //     int b1 = basket1[i];
        //     int b2 = basket2[j];

        //     if(b1 == b2){
        //         i++;
        //         j++;
        //         flag = false;
        //         continue;
        //     }
        //     else if(flag == true){
        //         return -1;
        //     }
        //     else{
        //         swap(basket1[i], basket2[j]);
        //         cost += min(basket1[i], basket2[j]);
        //         sort(basket1.begin(), basket1.end());
        //         sort(basket2.begin(), basket2.end());
        //         flag = true;
        //     }
        // }
        // return cost;    

        unordered_map<int, int> mp;
        int minEl = INT_MAX;

        for(int &x : basket1) {
            mp[x]++;
            minEl = min(minEl, x);
        }

        for(int &x : basket2) {
            mp[x]--;
            minEl = min(minEl, x);
        }

        vector<int> finalList;
        for(auto &it : mp) {
            int cost  = it.first;
            int count = it.second;

            if(count == 0) {
                continue;
            }

            if(count % 2 != 0) {
                return -1;
            }

            for(int c = 1; c <= abs(count)/2; c++) {
                finalList.push_back(cost);
            }
        }

        //sort(begin(finalList), end(finalList)); //no need to sort entire array
        nth_element(begin(finalList), begin(finalList)+finalList.size()/2, end(finalList));

        long long result = 0;
        for(int i = 0; i < finalList.size()/2; i++) {
            result += min(finalList[i], minEl*2);
        }

        return result;  
    }
};