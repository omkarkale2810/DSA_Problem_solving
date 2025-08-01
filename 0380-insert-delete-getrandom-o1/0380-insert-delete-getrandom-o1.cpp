class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }
        int idx = arr.size();
        arr.push_back(val);
        mp[val] = idx;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        int idx = mp[val];
        int last_idx = arr.size()-1;
        swap(arr[idx], arr[last_idx]);
        arr.pop_back();
        mp[arr[idx]] = idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = arr.size();
        int idx = rand()%n;
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */