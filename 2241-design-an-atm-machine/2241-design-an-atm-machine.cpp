class ATM {
public:
    vector<int> notes;
    unordered_map<int,int> mp;

    ATM() {
        notes = {0, 0, 0, 0, 0};
        mp[0] = 20;
        mp[1] = 50;
        mp[2] = 100;
        mp[3] = 200;
        mp[4] = 500;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++){
            notes[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);
        
        vector<int> temp(notes.begin(), notes.end());

        int idx  = 4;
        while(amount > 0){
            if(idx == -1){
                return {-1};
            }
            if(temp[idx] == 0){
                idx--;
                continue;
            }
            if(amount >= mp[idx]){
                int req_notes = amount/mp[idx];
                if(req_notes <= temp[idx]){
                    temp[idx] -= req_notes;
                    ans[idx] = req_notes;
                    amount -= mp[idx]*req_notes;
                }
                else{
                    ans[idx] =  temp[idx];
                    amount -= mp[idx]*temp[idx];
                    temp[idx] = 0;
                }
            }
            idx--;
        }
        notes = temp;
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */